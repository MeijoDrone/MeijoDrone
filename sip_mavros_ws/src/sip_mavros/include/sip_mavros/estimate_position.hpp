//
//  estimate_position.hpp
//  
//
//  Created by IKEDA Takahiro on 2017/09/06.
//
//

#ifndef estimate_position_hpp
#define estimate_position_hpp

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Point.h>
#include <tf2/LinearMath/Transform.h>
#include <tf/transform_listener.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/RCIn.h>
#include <std_msgs/Float64.h>


const double gravity=9.80665;

void Quat2RollPitchYaw(const geometry_msgs::Quaternion &q, double &roll, double &pitch, double &yaw);

void RollPitchYaw2Quat(geometry_msgs::Quaternion &q, double roll, double pitch, double yaw);

double remap(double in, double in_upper_lim, double in_lower_lim, double out_upper_lim, double out_lower_lim);


class TimeSet{
public:
    ros::Time raw;
    double initial;
    double current;
    double past;
    double diff;
    double limit;
    TimeSet(double diff_){
        initial = 0.0;
        current = 0.0;
        past    = 0.0;
        diff    = diff_;
        limit   = 1.0;
    }
    TimeSet(double diff_, double limit_){
        initial = 0.0;
        current = 0.0;
        past    = 0.0;
        diff    = diff_;
        limit   = limit_;
    }
    void update();
};



class Vector2{
public:
    double x, v;
    Vector2(double x_, double v_){
        x = x_;
        v = v_;
    }
    Vector2(){
        x = 0.0;
        v = 0.0;
    }
};
class Matrix2x2{
public:
    double a,b,c,d;
    Matrix2x2(double a_, double b_, double c_, double d_){
        a=a_;
        b=b_;
        c=c_;
        d=d_;
    }
    Matrix2x2(){
        a=1.0;
        b=0.0;
        c=0.0;
        d=1.0;
    }
};

class Kalman{
public:
    
    Vector2 vecZ;      //measured value
    Vector2 vecX_p;    //past predicted value
    Vector2 vecX_c;    //current predicted value
    Vector2 vecX_f;    //future predicted value
    Vector2 err;       //predictive error
    Matrix2x2 matP_p;  //past prediction error matrix
    Matrix2x2 matP_c;  //current prediction error matrix
    Matrix2x2 matP_f;  //future prediction error matrix
    Matrix2x2 matS;
    Matrix2x2 kGain;   //kalman gain
    
    Matrix2x2 coeF;    //internal state matrix
    Vector2 coeB;      //input matrix/vector
    Matrix2x2 coeG;    //state noise matrix
    Matrix2x2 coeH;    //measurement matrix
    Matrix2x2 coeR;    //covariance matrix
    Matrix2x2 coeQ;    //covariance matrix
    double input;
    Matrix2x2 unit;
    
    Kalman(double dt_);
    
    void MxM(Matrix2x2& out, Matrix2x2 a, Matrix2x2 b){
        out.a = a.a*b.a + a.b*b.c;
        out.b = a.a*b.b + a.b*b.d;
        out.c = a.c*b.a + a.d*b.c;
        out.d = a.c*b.b + a.d*b.d;
    }
    void inverseM(Matrix2x2& out, Matrix2x2 a){
        double temp = a.a*a.d - a.b*a.c;
        out.a = a.d/temp;
        out.b = -a.b/temp;
        out.c = -a.c/temp;
        out.d = a.a/temp;
    }
    void transposedM(Matrix2x2& out, Matrix2x2 a){
        out.a = a.a;
        out.b = a.c;
        out.c = a.b;
        out.d = a.d;
    }
    void MsumM(Matrix2x2& out, Matrix2x2 a, Matrix2x2 b){
        out.a = a.a + b.a;
        out.b = a.b + b.b;
        out.c = a.c + b.c;
        out.d = a.d + b.d;
    }
    void MsubM(Matrix2x2& out, Matrix2x2 a, Matrix2x2 b){
        out.a = a.a - b.a;
        out.b = a.b - b.b;
        out.c = a.c - b.c;
        out.d = a.d - b.d;
    }
    void MxV(Vector2& out, Matrix2x2 a, Vector2 b){
        out.x = a.a*b.x + a.b*b.v;
        out.v = a.c*b.x + a.d*b.v;
    }
    void VsumV(Vector2& out, Vector2 a, Vector2 b){
        out.x = a.x + b.x;
        out.v = a.v + b.v;
    }
    void VsubV(Vector2& out, Vector2 a, Vector2 b){
        out.x = a.x - b.x;
        out.v = a.v - b.v;
    }
    void predict();
    void update();
    void filter(Vector2& predicted, Vector2& measured, double& input, double& dtime);
};



class AccKalman{
public:
    
    Vector2 vecZ;      //measured value
    Vector2 vecX_p;    //past predicted value
    Vector2 vecX_c;    //current predicted value
    Vector2 vecX_f;    //future predicted value
    Vector2 err;       //predictive error
    Matrix2x2 matP_p;  //past prediction error matrix
    Matrix2x2 matP_c;  //current prediction error matrix
    Matrix2x2 matP_f;  //future prediction error matrix
    Matrix2x2 matS;
    Matrix2x2 kGain;   //kalman gain
    
    Matrix2x2 coeF;    //internal state matrix
    Vector2 coeB;      //input matrix/vector
    Matrix2x2 coeG;    //state noise matrix
    Matrix2x2 coeH;    //measurement matrix
    Matrix2x2 coeR;    //covariance matrix
    Matrix2x2 coeQ;    //covariance matrix
    double input;
    Matrix2x2 unit;
    
    AccKalman(double dt_);
    
    void MxM(Matrix2x2& out, Matrix2x2 a, Matrix2x2 b){
        out.a = a.a*b.a + a.b*b.c;
        out.b = a.a*b.b + a.b*b.d;
        out.c = a.c*b.a + a.d*b.c;
        out.d = a.c*b.b + a.d*b.d;
    }
    void inverseM(Matrix2x2& out, Matrix2x2 a){
        double temp = a.a*a.d - a.b*a.c;
        out.a = a.d/temp;
        out.b = -a.b/temp;
        out.c = -a.c/temp;
        out.d = a.a/temp;
    }
    void transposedM(Matrix2x2& out, Matrix2x2 a){
        out.a = a.a;
        out.b = a.c;
        out.c = a.b;
        out.d = a.d;
    }
    void MsumM(Matrix2x2& out, Matrix2x2 a, Matrix2x2 b){
        out.a = a.a + b.a;
        out.b = a.b + b.b;
        out.c = a.c + b.c;
        out.d = a.d + b.d;
    }
    void MsubM(Matrix2x2& out, Matrix2x2 a, Matrix2x2 b){
        out.a = a.a - b.a;
        out.b = a.b - b.b;
        out.c = a.c - b.c;
        out.d = a.d - b.d;
    }
    void MxV(Vector2& out, Matrix2x2 a, Vector2 b){
        out.x = a.a*b.x + a.b*b.v;
        out.v = a.c*b.x + a.d*b.v;
    }
    void VsumV(Vector2& out, Vector2 a, Vector2 b){
        out.x = a.x + b.x;
        out.v = a.v + b.v;
    }
    void VsubV(Vector2& out, Vector2 a, Vector2 b){
        out.x = a.x - b.x;
        out.v = a.v - b.v;
    }
    void predict();
    void update();
    void filter(Vector2& predicted, Vector2& measured, double& input, double& dtime);
};



class Estimation{
public:
    TimeSet time;
    geometry_msgs::Vector3 body_accel;
    geometry_msgs::Vector3 measured_accel;
    geometry_msgs::Vector3 measured_velocity;
    geometry_msgs::Vector3 accel;
    geometry_msgs::Vector3 velocity;
    geometry_msgs::Vector3 position;
    Vector2 measured_x;
    Vector2 measured_y;
    Vector2 measured_z;
    Vector2 predicted_x;
    Vector2 predicted_y;
    Vector2 predicted_z;
    
    AccKalman kalman_x;
    AccKalman kalman_y;
    AccKalman kalman_z;
    
    Estimation();
    
    void position_update(geometry_msgs::Vector3 sensor_velocity, sensor_msgs::Imu sensor_imu, double yaw, geometry_msgs::Vector3 input, geometry_msgs::Vector3 measured_position, bool refresh);

};

class LPF{//low pass filter
public:
    double k;
    double b[1][2];
    double a[1][3];
    double in;
    double out;
    double x[3];
    int initialize;
    
    LPF();
    LPF(int mode);
    
    double filter(double data);
};

class Ground_class{
public:
    LPF filter;
    TimeSet tm;
    double initial;
    double current;
    double past;
    double velocity;
    double raw;
    double raw_current;
    double raw_past;
    double raw_diff;
    Kalman kalman;
    Vector2 measured;
    Vector2 predicted;
    double input;
    
    Ground_class(double tm_diff_);
    
    void update(double data, double roll, double pitch);
};


#endif /* estimate_position_hpp */
