# MeijoDrone in English
SetUp
Autopilot firmware (PX4) on Pixhawk,
Ubuntu running on companion computer,
laser altitude meter (SF10/B, lightware),
laser range meter(Simple URG/Top URG, Hokuyo) for SLAM which estimates self horisontal position\
All components are connected via ROS.\
When a desired waypoint is input as ROS service, ramp desired trajectory is generated.

Install "mavros" to connect Pixhawk and the companion computer with MAVLINK protocol.\
user:\~$ sudo apt-get install ros-kinetic-mavros\
user:\~$ sudo apt-get install ros-kinetic-mavros-extras\
user:\~$ sudo apt-get install ros-kinetic-mavros-msgs\
when the connection can not be made with error massage mentioning "install_geographiclib_datasets.sh", execute follows\
user:/opt/ros/kinetic/lib/mavros$ sudo ./install_geographiclib_datasets.sh

Three following packages are in this repository.\
sip_mavros_ws （Position control）\
sip_tf_manager_ws （Manages Transformation matrix）\
sip_scenario_ws (Generates ramp desired trajectory）

To handle the sensors and SLAM on ROS, download following packages.\
ros_lightware <https://github.com/wavelab/ros_lightware>\
cereal_port <https://github.com/wavelab/cereal_port>\
hokuyo_node <https://github.com/ros-drivers/hokuyo_node> ("urg_node" is also avarable)\
hector_slam <https://github.com/tu-darmstadt-ros-pkg/hector_slam>\
hector_slam_example <https://github.com/DaikiMaekawa/hector_slam_example>

Make "lightware_ws" including "ros_lightware" and "cereal_port" packages for altitude measurement.\
Make "hokuyo_node_ws" including "hokuyo_node" (or "urg_node") for laser range finder.\
Make "hector_slam_ws" including "hector_slam" and "hector_slam_example" for handling SLAM.

In "sip_mavros_node," position control consists of position, velocity and acceleration PID feedbacks parallelly.\
There is PID parameter file in "sip_mavros_ws" directory as following.\
param_hexa.xml\
The parameter should be modified proper value for your UAV.
There are two parameter sets in the UAV system including Autopilot: parameters of attitude control in Autopilot and this parameters of position control.
First, modify the parameters of attitude control.
It is recommended to execute auto tune on Autopilot.
Then, modify the parameters of position control.

There is a shell script to rosrun all nodes in this repository. The work-space directories are named as above, the shell script can be used without any editing. Put the work spaces and the script at same directory. Start "tmux," which separates terminal into multi window, at the directory, then start the script.\
start_drone.sh

Summarize the role of each window created by the script as following.\
0: sip_mavros_node\
1: hector SLAM\
2: connection to Pixhawk, and state message\
3: Input desired waypoint (meter) "target: x:front y:left z:above”（before input, push "tab key" once）\
4: rosbag, which records log in ROS, command is inserted\
5: hokuyo_node\
6: sip_tf_manager_node\
7: Display altitude topic（/altitude）\
8: ros_scenario_node\
9: lightware_node\
10: roscoe\
11: command, which terminates sip_mavros_node, is inserted

sip_mavros_node refers the value of radio controller (RC) via Pixhawk and MAVROS. Seven sticks of RC are used in sip_mavros_node. Set each stick with appropriate number.\
•Roll stick (sw 0): control roll in manual mode/ emergency manual interruption in auto mode (tilt the stick ±50 in digital value of RC)\
•Pitch stick (sw 1): control pitch in manual mode/ emergency manual interruption in auto mode (tilt the stick ±50 in digital value of RC)\
•Yaw stick (sw 3): control yaw in manual mode/ emergency manual interruption in auto mode (tilt the stick ±50 in digital value of RC)\
•Trim stick (sw 5): modify desired altitude rate R (Highest R = 1 \~ Lowest R = 0, desired altitude = input altitude * R)\
•Arbitrary stick (sw 6): HIGH = start program, LOW = end program\
•Arbitrary stick (sw 8): HIGH = manual control, LOW = auto control\
•Arbitrary stick: switch Offboard Mode of Pixhawk (the node does not refer this value)

Start sip_mavros_node on terminal, then the program wait for switching Offboard Mode.\
Switch Offboard Mode, then the program wait to be started by sw 6.\
After the program is started, the props start to rotate. Input desired position on the terminal.\
The desired altitude can be modified by using sw 5.\
If the program is interrupted by roll/pitch/yaw stick as emergency manual interruption in auto control, the control method is fixed as manual control (it cannot reset into auto control). Note, the altitude is controlled automatically in manual control mode.\
When finish the program, set the desired altitude less than 0 m and confirm that the altitude becomes enough low, then switch sw 6 to finish. sw 6 can work when UAV hovers, therefore the switch works as emergency stop switch.

Summarize topics of subscriber and publisher in each node.\
sip_mavros_node (in sip_mavros_ws)\
Subscriber:\
"mavros/state" <mavros_msgs::State> \
"/sip/target_point" <geometry_msgs::Point>\
"/sip/target_yaw" <std_msgs::Float64>\
"/sip/quit" <std_msgs::Empty>\
"/mavros/rc/in" <mavros_msgs::RCIn>\
"/mavros/battery" <sensor_msgs::BatteryState>\
"/slam_out_pose" <geometry_msgs::PoseStamped>\
"/altitude" <std_msgs::Float64>\
"/mavros/imu/data" <sensor_msgs::Imu>\
Publisher:\
"mavros/setpoint_raw/attitude" <mavros_msgs::AttitudeTarget>\
"mavros/cmd/arming" <mavros_msgs::CommandBool>\
"mavros/set_mode" <mavros_msgs::SetMode>


sip_tf_manager_node (in sip_tf_manager_ws)\
Subscriber:\
/altitude <std_msgs::Float64>\
/mavros/imu/data <sensor_msgs::Imu>\
/slam_out_pose <geometry_msgs::PoseStamped>\
Publisher:\
TF


sip_scenario_node (in sip_scenario_ws)\
Publisher:\
/sip/target_point <geometry_msgs::Point>


hokuyo_node (in hokuyo_ws)\
Publisher:\
/scan <sensor_msgs::LaserScan


hector_slam_node (hector_slam)\
Publisher:\
/slam_out_pose <geometry_msgs::PoseStamped>


lightware_node (in lightware_ws)\
Publisher:\
"/altitude" <std_msgs::Float64> (changed)

