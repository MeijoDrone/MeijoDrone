//
//  kalmanFilter.cpp
//  
//
//  Created by IKEDA Takahiro on 2017/07/26.
//
//

#include <stdio.h>
#include <math.h> // atan2()
#include <limits.h> // isnan()
#include <stdlib.h>
#include <string>
#include <vector>
#include <ros/ros.h>

#include <std_msgs/Float64.h>
#include <std_msgs/Int8.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Vector3.h>
#include <sensor_msgs/Imu.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/RCIn.h>
#include <tf2/LinearMath/Transform.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/WrenchStamped.h>

#include "sip_mavros/kalman_filter.h"

Kalman::Kalman(double dt_)
: vecZ()      //measured value
, vecX_p()    //past predicted value
, vecX_c()    //current predicted value
, vecX_f()    //future predicted value
, err()       //predictive error
, matP_p()    //past prediction error matrix
, matP_c()    //current prediction error matrix
, matP_f()    //future prediction error matrix
, matS()
, kGain()     //kalman gain
, coeF(1.0, dt_, 0.0, 1.0)//internal state matrix
, coeB(pow(dt_,2)/2, dt_)//input matrix/vector
, coeG()      //state noise matrix
, coeH()      //measurement matrix
, coeR()      //covariance matrix
, coeQ()      //covariance matrix
, input(0.0)
, unit()
{
}
void Kalman::predict(){
    vecX_p = vecX_f;
    Vector2 temp1;
    Vector2 temp2;
    MxV(temp1, coeF, vecX_p);
    temp2.x = coeB.x * input;
    temp2.v = coeB.v * input;
    VsumV(vecX_c, temp1, temp2);

    matP_p = matP_f;
    Matrix2x2 temp3;
    Matrix2x2 temp4;
    Matrix2x2 temp5;
    transposedM(temp3,coeG);
    MxM(temp4,coeQ,temp3);
    MxM(temp3,coeG,temp4);
    transposedM(temp4,coeF);
    MxM(temp5,matP_p,temp4);
    MxM(temp4,coeF,temp5);
    MsumM(matP_c,temp4,temp3);
}
void Kalman::update(){
    Vector2 temp1;
    MxV(temp1,coeH,vecX_c);
    VsubV(err,vecZ,temp1);
    
    Matrix2x2 temp2;
    Matrix2x2 temp3;
    Matrix2x2 temp4;
    transposedM(temp2,coeH);
    MxM(temp3,matP_c,temp2);
    MxM(temp2,coeH,temp3);
    MsumM(matS,coeR,temp2);
    
    inverseM(temp2,matS);
    transposedM(temp3,coeH);
    MxM(temp4,temp3,temp2);
    MxM(kGain,matP_c,temp4);
    
    MxV(temp1,kGain,err);
    VsumV(vecX_f,vecX_c,temp1);
    
    MxM(temp2,kGain,coeH);
    MsubM(temp3,unit,temp2);
    MxM(matP_f,temp3,matP_c);
}
void Kalman::filter(Vector2& predicted, Vector2& measured, double& input, double& dtime){
    vecZ = measured;
    input = input;
    coeF.b = dtime;
    coeB.x = pow(dtime,2)/2;
    coeB.v = dtime;
    predict();
    update();
    predicted = vecX_f;
}
