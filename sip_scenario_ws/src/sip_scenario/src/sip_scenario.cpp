#include <string>
#include <stdlib.h> // getopt(), exit()
#include <algorithm> // std::max()
#include "ros/ros.h"
#include "geometry_msgs/Point.h"
#include "std_msgs/Float64.h"
#include <std_msgs/Int8.h>
#include "geometry_msgs/WrenchStamped.h"
#include "tf/transform_listener.h"
#include "sip_scenario/LampInput.h"
#include "sip_scenario/NearToFloor.h"
#include "sip_scenario/AccessToFloor.h"
#include "sip_scenario/LeaveFromFloor.h"
#include "sip_scenario/StopScenario.h"


#define Hover 0
#define ContactSlab 1

enum ScenarioIndex
{
	ScenarioNone
		, ScenarioLampInput
		, ScenarioLeaveFromFloor
		, ScenarioNearToFloor
		, ScenarioAccessToFloor
};

class SipScenarioMem
{
	public:
		tf::TransformListener listener;
		tf::StampedTransform current_transform;
		geometry_msgs::Point target_point;
        std_msgs::Int8 moving_mode;

		ScenarioIndex scenario;
		bool play_scenario;
		ros::Time prev;
		tf::Vector3 current_position;
		bool recv_floor;
		bool recv_wrench;

		// for LampInput
		const double lamp_input_meters_per_sec;
		geometry_msgs::Point lamp_end_point;
    geometry_msgs::Point past_lamp_end_point;

		// for NearToFloor
		double distance_floor;
		double near_target_distance;

		// for AccessToFloor
		double access_force;
		geometry_msgs::WrenchStamped wrench;

		// for LeaveFromFloor
		double leave_distance;

		SipScenarioMem()
			: listener()
			  , current_transform()
			  , target_point()
              , moving_mode()
			  , scenario(ScenarioNone)
			  , play_scenario(false)
			  , prev(ros::Time::now())
			  , current_position()
			  , recv_floor(false)
			  , recv_wrench(false)
			  , lamp_input_meters_per_sec(0.3/*[m/s]*/)
			  , lamp_end_point()
    ,past_lamp_end_point()
			  , distance_floor(0.0)
			  , near_target_distance(2.0)
			  , access_force(0.0)
			  , wrench()
			  , leave_distance(0.0)
		{
		}

		double deviation(const geometry_msgs::Point &pa, const geometry_msgs::Point &pb)
		{
			return sqrt(pow(pa.x - pb.x, 2.0)
					+ pow(pa.y - pb.y, 2.0)
					+ pow(pa.z - pb.z, 2.0));
		}

		bool updateTransform()
		{
			try
			{
				listener.lookupTransform("map", "base_frame", ros::Time(0), current_transform);
            }
			catch(tf::TransformException ex)
			{
				ROS_ERROR("YAMAKAZE> %s", ex.what());
				return false;
			}
			current_position = current_transform.getOrigin();
			return true;
		}

		void readScenario()
		{
			if(scenario == ScenarioNone)
			{
				play_scenario = false;
			}
			else if(scenario == ScenarioLampInput)
			{
                moving_mode.data = Hover;
				double rest_err = deviation(target_point, lamp_end_point);
				ros::Duration ros_dt = ros::Time::now() - prev;
				double dt = ros_dt.sec + ros_dt.nsec * 0.000000001;
				if(rest_err < lamp_input_meters_per_sec * 0.01){
					ROS_INFO("YAMAKAZE> Complate Lamp Control.");
					ROS_INFO("YAMAKAZE> You have control.");
					target_point = lamp_end_point;
					scenario = ScenarioNone;
				}else{
					target_point.x
						+= dt
						* lamp_input_meters_per_sec
						* (lamp_end_point.x - target_point.x)
						/ rest_err;
					target_point.y
						+= dt
						* lamp_input_meters_per_sec
						* (lamp_end_point.y - target_point.y)
						/ rest_err;
					target_point.z
						+= dt
						* lamp_input_meters_per_sec
						* (lamp_end_point.z - target_point.z)
						/ rest_err;
				}
			}
			else if (scenario == ScenarioLeaveFromFloor)
			{
                moving_mode.data = Hover;
				target_point.x = current_position.getX();
				target_point.y = current_position.getY();
				target_point.z = current_position.getZ()
					- leave_distance/*m*/;

				ROS_INFO("YAMAKAZE> Finish Leaving from floor.");
				ROS_INFO("YAMAKAZE> You have control.");
				scenario = ScenarioNone;
			}
			else if(scenario == ScenarioNearToFloor)
			{
                moving_mode.data = Hover;
				target_point.x = current_position.getX();
				target_point.y = current_position.getY();
				target_point.z += 0.001/*m*/
					* (distance_floor - near_target_distance);
			}
			else if(scenario == ScenarioAccessToFloor)
			{
                moving_mode.data = ContactSlab;
				target_point.x = current_position.getX();
				target_point.y = current_position.getY();
				target_point.z += 0.0001/*m*/
					* (access_force
							- std::max(wrench.wrench.force.z
								* -1.0
								, 0.0));
			}
			else
			{
				play_scenario = false;
			}
		}

		bool lampInput_srv(sip_scenario::LampInput::Request &req
				, sip_scenario::LampInput::Response &res)
		{
			scenario = ScenarioLampInput;
			play_scenario = true;

            past_lamp_end_point = target_point;
            printf("%lf %lf %lf\n", past_lamp_end_point.x,past_lamp_end_point.y,past_lamp_end_point.z);
			lamp_end_point = req.target;

            double tempX = current_position.getX();
            double tempY = current_position.getY();
            double tempZ = current_position.getZ();
            if(tempZ < 0.3){
                target_point.x = tempX;
                target_point.y = tempY;
                target_point.z = tempZ;
                if(lamp_end_point.z > 0.3){
                    lamp_end_point.x = tempX;
                    lamp_end_point.y = tempY;
                }
            }else{
                if(fabs(past_lamp_end_point.x - tempX)>0.5){
                    target_point.x = tempX;
                }
                if(fabs(past_lamp_end_point.y - tempY)>0.5){
                    target_point.y = tempY;
                }
            }

			ROS_INFO("YAMAKAZE> Start Lamp Input Control.");

			res.success = true;
			return true;
		}

		bool accessToFloor_srv(sip_scenario::AccessToFloor::Request &req
				, sip_scenario::AccessToFloor::Response &res)
		{
			if(not recv_wrench)
			{
				ROS_WARN("YAMAKAZE> No Force Sensor.");
				ROS_WARN("YAMAKAZE> Cannot detect floor.");
				res.success = false;
				return false;
			}

			scenario = ScenarioAccessToFloor;
			play_scenario = true;

			access_force = req.force;
			target_point.x = current_position.getX();
			target_point.y = current_position.getY();
			target_point.z = current_position.getZ();

			ROS_INFO("YAMAKAZE> I have control.");
			ROS_INFO("YAMAKAZE> Start access to floor.");
			ROS_INFO("SYSTEM> force: %f [N]", access_force);

			res.success = true;
			return true;
		}

		bool nearToFloor_srv(sip_scenario::NearToFloor::Request &req
				, sip_scenario::NearToFloor::Response &res)
		{
			if(not recv_floor)
			{
				ROS_WARN("YAMAKAZE> No Distance Sensor.");
				ROS_WARN("YAMAKAZE> Cannot detect floor.");
				res.success = false;
				return false;
			}

			scenario = ScenarioNearToFloor;
			play_scenario = true;

			near_target_distance = req.distance;
			target_point.x = current_position.getX();
			target_point.y = current_position.getY();
			target_point.z = current_position.getZ();

			ROS_INFO("YAMAKAZE> I have control.");
			ROS_INFO("YAMAKAZE> Start near to floor.");
			ROS_INFO("SYSTEM> target distance: %f [m]", near_target_distance);

			res.success = true;
			return true;
		}

		bool leaveFromFloor_srv(sip_scenario::LeaveFromFloor::Request &req
				, sip_scenario::LeaveFromFloor::Response &res)
		{
			scenario = ScenarioLeaveFromFloor;
			play_scenario = true;

			ROS_INFO("YAMAKAZE> I have control.");
			ROS_INFO("YAMAKAZE> Leave from floor.");

			res.success = true;
			return true;
		}

		bool stopScenario_srv(sip_scenario::StopScenario::Request &req
				, sip_scenario::StopScenario::Response &res)
		{
			scenario = ScenarioNone;

			ROS_INFO("YAMAKAZE> Cancel scenario.");

			res.success = true;
			return true;
		}

		void floor_cb(const std_msgs::Float64ConstPtr &msg)
		{
			recv_floor = true;
			distance_floor = msg->data;
		}

		void wrench_cb(const geometry_msgs::WrenchStampedConstPtr &msg)
		{
			recv_wrench = true;
			wrench = *msg;
		}

		void quit_cb(const std_msgs::EmptyConstPtr &msg)
		{
			scenario = ScenarioNone;

			ROS_INFO("YAMAKAZE> Finish operation.");
		}
};

void readme(const char *name)
{
	ROS_INFO("YAMAKAZE> \n\
			Usage: %s\n\
			-f <floor laser topic std_msgs::Float64 subscribe>\n\
			-w <wrench topic geometry_msgs::WrenchStamped subscribe>\n\
			\n\
			Ex: %s\n\
			-f /laser/floor\n\
			-w /leptrino_com/force_torque\n\
			\n", name, name);
}

void cmd_arguments(int argc, char **argv
		, std::string &floor_topic
		, std::string &wrench_topic
		)
{
	int result;
	while((result = getopt(argc, argv, "hf:w:")) != -1)
	{
		switch(result)
		{
			case 'h':
				readme(argv[0]);
				exit(0);
			case 'f':
				floor_topic = std::string(optarg);
				break;
			case 'w':
				wrench_topic = std::string(optarg);
				break;
		}
	}
}

int main(int argc, char **argv)
{
	std::string floor_topic("/laser/floor");
	std::string wrench_topic("/leptrino_com/force_torque");
	cmd_arguments(argc, argv
			, floor_topic
			, wrench_topic
			);
	ros::init(argc, argv, "sip_scenario");
	SipScenarioMem ssm;
	ros::NodeHandle nh;
	ros::ServiceServer lamp_serv
		= nh.advertiseService("lamp"
			, &SipScenarioMem::lampInput_srv, &ssm);
	ros::ServiceServer leave_serv
		= nh.advertiseService("leave_from_floor"
			, &SipScenarioMem::leaveFromFloor_srv, &ssm);
	ros::ServiceServer near_serv
		= nh.advertiseService("near_to_floor"
			, &SipScenarioMem::nearToFloor_srv, &ssm);
	ros::ServiceServer access_serv
		= nh.advertiseService("access_to_floor"
			, &SipScenarioMem::accessToFloor_srv, &ssm);
	ros::ServiceServer stop_serv
		= nh.advertiseService("stop"
			, &SipScenarioMem::stopScenario_srv, &ssm);
	ros::Subscriber floor_sub
		= nh.subscribe<std_msgs::Float64>(floor_topic.c_str()
				, 10, &SipScenarioMem::floor_cb, &ssm);
	ros::Subscriber wrench_sub
		= nh.subscribe<geometry_msgs::WrenchStamped>(
				wrench_topic.c_str()
				, 10, &SipScenarioMem::wrench_cb, &ssm);
	ros::Subscriber quit_sub
		= nh.subscribe<std_msgs::Empty>(
				"/sip/quit"
				, 10, &SipScenarioMem::quit_cb, &ssm);
	ros::Publisher target_pub
		= nh.advertise<geometry_msgs::Point>("/sip/target_point", 10);
    ros::Publisher mode_pub
        = nh.advertise<std_msgs::Int8>("/sip/moving_mode", 10);
	ros::Rate rate(200);
	while(ros::ok())
	{
		ssm.updateTransform();
		if(ssm.play_scenario)
		{
			ssm.readScenario();
			target_pub.publish(ssm.target_point);
		}
        mode_pub.publish(ssm.moving_mode);
		ssm.prev = ros::Time::now();

		ros::spinOnce();
		rate.sleep();
	}
	return 0;
}
