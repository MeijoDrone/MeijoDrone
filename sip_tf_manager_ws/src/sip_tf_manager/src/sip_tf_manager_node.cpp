//
//  sip_tf_manager_node.cpp
//  
//
//  Created by IKEDA Takahiro on 2017/04/07.
//
//

#include <stdio.h>
#include <math.h>

#include "ros/ros.h"
#include "tf/transform_broadcaster.h"
#include <geometry_msgs/PoseStamped.h>
#include <sensor_msgs/Imu.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int16.h>
#include <geometry_msgs/Vector3.h>

//tf::TransformBroadcaster* tfB_;
tf::StampedTransform map_odm_trns;
tf::StampedTransform odm_foot_trns;
tf::StampedTransform foot_blink_trns;
tf::StampedTransform blink_stb_trns;
tf::StampedTransform stb_copter_trns;
tf::StampedTransform copter_urg_trns;
tf::StampedTransform copter_alt_trns;
tf::StampedTransform copter_imu_trns;

class LPFalt{
public:
    double k;
    double b[1][2];
    double a[1][3];
    double in;
    double out;
    double x[3];
    int initialize;
    
    LPFalt(){
        /*cut off freq = 2.1, stop freq = 12.5,samp freq=32.2, late=80ms*/
        k = 0.154239871134214918;
        b[0][0] = -1.08138205505268603;
        b[0][1] = 0.386455883094752650;
        a[0][0] = 0.494479517194034046;
        a[0][1] = 0.988959034388068092;
        a[0][2] = 0.494479517194034046;
        in = 0;
        out = 0;
        initialize = 0;
        for(int i=0;i<3;i++){
            x[i]=0;
        }
    }
    double filter(double data);
};
double LPFalt::filter(double data){
    if(initialize>0){
        x[0]=x[1]=x[2]=data;
        initialize--;
    }
    in = data;
    x[2] = x[1];
    x[1] = x[0];
    x[0] = k*in - (b[0][0]*x[1] + b[0][1]*x[2]);
    out = a[0][0]*x[0] + a[0][1]*x[1] + a[0][2]*x[2];
    return out;
}

class Mean{
public:
    double in;
    double buff[10];
    double out;
    int cnt;
    
    Mean();
    
    double move_ave(double raw){
        in = (double)raw;
        buff[cnt] = in;
        out = 0.0;
        for(int i=0; i<10; i++){
            out += buff[i];
        }
        out = out/10;
        cnt = (cnt+1)%10;
        return out;
    }
};
Mean::Mean(){
    in = 0.0;
    out = 0.0;
    cnt=0;
    for(int i=0; i<10; i++){
        buff[i]=0.0;
    }
}


class Member{
public:
    ros::NodeHandle nh;
    ros::Subscriber imu_sub;
    ros::Subscriber slam_sub;
    ros::Subscriber alt_sub;
    ros::Rate rate;
    
    
    Mean rollMean;
    Mean pitchMean;
    Mean yawMean;
    Mean xMean;
    Mean yMean;
    Mean zMean;
    
    double dYawInit;
    double dYawCrr;
    double dYaw;
    double slamYaw;
    
    geometry_msgs::Vector3 attitude;
    double ground_alt;
    
    Member(double freq_);
    
    void imu_cb(const sensor_msgs::Imu &msg){
        static tf::TransformBroadcaster tfB_;
        tf::Quaternion tmp_att_;
        tf::Vector3 tmp_posi_;
        
        tf::quaternionMsgToTF(msg.orientation, tmp_att_);
        tfScalar yaw, pitch, roll;
        tf::Matrix3x3(tmp_att_).getRPY(roll, pitch, yaw);
        
        dYawCrr = yaw;
        roll = rollMean.move_ave(roll);
        pitch = pitchMean.move_ave(pitch);
        yaw = 0.0;
        tmp_att_.setRPY(roll, pitch, yaw);
        attitude.x = roll;
        attitude.y = pitch;
        
        tmp_posi_.setX(0.0);
        tmp_posi_.setY(0.0);
        tmp_posi_.setZ(0.0);
        
        stb_copter_trns.setRotation(tmp_att_);
        stb_copter_trns.setOrigin(tmp_posi_);
        stb_copter_trns.stamp_ = ros::Time::now()/*msg.header.stamp*/;
        tfB_.sendTransform(stb_copter_trns);
    }
    
    void slam_cb(const geometry_msgs::PoseStamped &msg){
        double tmp = 0.0;
        static tf::TransformBroadcaster tfB_;
        tf::Quaternion tmp_att_;
        tf::Vector3 tmp_posi_;
        
        tf::quaternionMsgToTF(msg.pose.orientation, tmp_att_);
        tfScalar yaw, pitch, roll;
        tf::Matrix3x3(tmp_att_).getRPY(roll, pitch, yaw);
        roll = 0.0;
        pitch = 0.0;
        tmp_att_.setRPY(roll, pitch, yaw);
        attitude.z = yaw;
        
        tmp_posi_.setX(msg.pose.position.x);
        tmp_posi_.setY(msg.pose.position.y);
        tmp_posi_.setZ(0.0);
        
        map_odm_trns.setRotation(tmp_att_);
        map_odm_trns.setOrigin(tmp_posi_);
        map_odm_trns.stamp_ = ros::Time::now()/*msg.header.stamp*/;
        tfB_.sendTransform(map_odm_trns);
        
        dYawInit = dYawCrr;
        slamYaw = yaw;
    }
    
    void alt_cb(const std_msgs::Float64 &msg){
        ground_alt = zMean.move_ave((double)(msg.data*cos(attitude.x)*cos(attitude.y)));
        static tf::TransformBroadcaster tfB_;
        tf::Quaternion tmp_att_;
        tf::Vector3 tmp_posi_;
        tmp_att_.setRPY(0.0, 0.0, 0.0);
        tmp_posi_.setX(0.0);
        tmp_posi_.setY(0.0);
        tmp_posi_.setZ((float)ground_alt);
        foot_blink_trns.setRotation(tmp_att_);
        foot_blink_trns.setOrigin(tmp_posi_);
        foot_blink_trns.stamp_ = ros::Time::now();//msg.header.stamp;
        tfB_.sendTransform(foot_blink_trns);
    }
};
Member::Member(double freq_)
:imu_sub()
,slam_sub()
,alt_sub()
,rate(freq_)
,dYawInit(0.0)
,dYawCrr(0.0)
,dYaw(0.0)
,slamYaw(0.0)
,attitude()
,ground_alt(0.0)
{
    imu_sub =nh.subscribe("/mavros/imu/data", 10, &Member::imu_cb, this);
    slam_sub = nh.subscribe("/slam_out_pose", 1, &Member::slam_cb, this);
    alt_sub = nh.subscribe("/altitude", 10, &Member::alt_cb, this);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "sip_broadcaster_node");
    
    static tf::TransformBroadcaster tfB;
    tf::Quaternion zero_att;
    tf::Vector3 zero_posi;
    zero_att.setRPY(0.0, 0.0, 0.0);
    zero_posi.setX(0.0);
    zero_posi.setY(0.0);
    zero_posi.setZ(0.0);
    tf::Quaternion temp_att;
    tf::Vector3 temp_posi;
    temp_att.setRPY(0.0, 0.0, 0.0);
    temp_posi.setX(0.0);
    temp_posi.setY(0.0);
    temp_posi.setZ(0.0);
    
    
    map_odm_trns.frame_id_ = std::string("map");
    map_odm_trns.child_frame_id_ = std::string("odom");
    odm_foot_trns.frame_id_ = std::string("odom");
    odm_foot_trns.child_frame_id_ = std::string("base_footprint");
    foot_blink_trns.frame_id_ = std::string("base_footprint");
    foot_blink_trns.child_frame_id_ = std::string("base_link");
    blink_stb_trns.frame_id_ = std::string("base_link");
    blink_stb_trns.child_frame_id_ = std::string("base_stabilized");
    stb_copter_trns.frame_id_ = std::string("base_stabilized");
    stb_copter_trns.child_frame_id_ = std::string("base_frame");
    copter_urg_trns.frame_id_ = std::string("base_frame");
    copter_urg_trns.child_frame_id_ = std::string("laser");
    copter_alt_trns.frame_id_ = std::string("base_frame");
    copter_alt_trns.child_frame_id_ = std::string("alt");
    copter_imu_trns.frame_id_ = std::string("base_frame");
    copter_imu_trns.child_frame_id_ = std::string("fc_imu");
    
    map_odm_trns.setRotation(zero_att);
    map_odm_trns.setOrigin(zero_posi);
    map_odm_trns.stamp_ = ros::Time::now();
    tfB.sendTransform(map_odm_trns);
    
    odm_foot_trns.setRotation(zero_att);
    odm_foot_trns.setOrigin(zero_posi);
    odm_foot_trns.stamp_ = ros::Time::now();
    tfB.sendTransform(odm_foot_trns);
    
    foot_blink_trns.setRotation(zero_att);
    foot_blink_trns.setOrigin(zero_posi);
    foot_blink_trns.stamp_ = ros::Time::now();
    tfB.sendTransform(foot_blink_trns);
    
    blink_stb_trns.setRotation(zero_att);
    blink_stb_trns.setOrigin(zero_posi);
    blink_stb_trns.stamp_ = ros::Time::now();
    tfB.sendTransform(blink_stb_trns);
    
    stb_copter_trns.setRotation(zero_att);
    stb_copter_trns.setOrigin(zero_posi);
    stb_copter_trns.stamp_ = ros::Time::now();
    tfB.sendTransform(stb_copter_trns);
    
    temp_att.setRPY(0.0, 0.0, 0.0);
    temp_posi.setX(0.0);
    temp_posi.setY(0.0);
    temp_posi.setZ(0.14);
    copter_urg_trns.setRotation(temp_att);
    copter_urg_trns.setOrigin(temp_posi);
    copter_urg_trns.stamp_ = ros::Time::now();
    tfB.sendTransform(copter_urg_trns);

    temp_att.setRPY(0.0, 0.0, 0.0);
    temp_posi.setX(0.0);
    temp_posi.setY(0.0);
    temp_posi.setZ(-0.2);
    copter_alt_trns.setRotation(temp_att);
    copter_alt_trns.setOrigin(temp_posi);
    copter_alt_trns.stamp_ = ros::Time::now();
    tfB.sendTransform(copter_alt_trns);

    temp_att.setRPY(0.0, 0.0, 0.0);
    temp_posi.setX(0.0);
    temp_posi.setY(0.0);
    temp_posi.setZ(0.0);
    copter_imu_trns.setRotation(temp_att);
    copter_imu_trns.setOrigin(temp_posi);
    copter_imu_trns.stamp_ = ros::Time::now();
    tfB.sendTransform(copter_imu_trns);
    
    Member member(10.0);

    ros::AsyncSpinner spinner(1);
    spinner.start();
    while(ros::ok()){
        member.dYaw = member.dYawCrr - member.dYawInit;
        temp_att.setRPY(0.0, 0.0, member.slamYaw+member.dYaw);
        map_odm_trns.setRotation(temp_att);
        
        map_odm_trns.stamp_ = ros::Time::now();
        tfB.sendTransform(map_odm_trns);
        odm_foot_trns.stamp_ = ros::Time::now();
        tfB.sendTransform(odm_foot_trns);
        foot_blink_trns.stamp_ = ros::Time::now();
        tfB.sendTransform(foot_blink_trns);
        blink_stb_trns.stamp_ = ros::Time::now();
        tfB.sendTransform(blink_stb_trns);
        stb_copter_trns.stamp_ = ros::Time::now();
        tfB.sendTransform(stb_copter_trns);
        copter_urg_trns.stamp_ = ros::Time::now();
        tfB.sendTransform(copter_urg_trns);
        copter_alt_trns.stamp_ = ros::Time::now();
        tfB.sendTransform(copter_alt_trns);
        copter_imu_trns.stamp_ = ros::Time::now();
        tfB.sendTransform(copter_imu_trns);
         
        member.rate.sleep();
    }
    
    return 0;
    
}
