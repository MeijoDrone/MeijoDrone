//
//  estimate_position.cpp
//  
//
//  Created by IKEDA Takahiro on 2017/09/06.
//
//  This program estimates position and velocity from acceleration of IMU.
//  Integrated acceleration is reset by RC ARM.
//  Therefore MAVROS node has to be started.

#include "sip_mavros/estimate_position.hpp"

void Quat2RollPitchYaw(const geometry_msgs::Quaternion &q, double &roll, double &pitch, double &yaw){
    tf2::Quaternion q_tf2(q.x, q.y, q.z, q.w);
    tf2::Matrix3x3(q_tf2).getRPY(roll, pitch, yaw);
}

void RollPitchYaw2Quat(geometry_msgs::Quaternion &q, double roll, double pitch, double yaw){
    tf2::Quaternion q_tf2(q.x, q.y, q.z, q.w);
    q_tf2.setRPY(roll, pitch, yaw);
    q.x = q_tf2.x();
    q.y = q_tf2.y();
    q.z = q_tf2.z();
    q.w = q_tf2.w();
}

//value of radio control -> desired values, angle and so on
double remap(double in
             , double in_upper_lim, double in_lower_lim
             , double out_upper_lim, double out_lower_lim)
{
    double ret =  (in - in_lower_lim)
    * (out_upper_lim - out_lower_lim)
    / (in_upper_lim - in_lower_lim)
    + out_lower_lim;
    if(ret < out_lower_lim){ret = out_lower_lim;}
    if(ret > out_upper_lim){ret = out_upper_lim;}
    return ret;
}

void TimeSet::update(){
    raw = ros::Time::now();
    if(initial == 0.0){
        initial = (double)(raw.sec)+(double)(raw.nsec)/1000000000.0;
        current = 0.0;
        past    = 0.0;
    }else{
        past = current;
        current = (double)(raw.sec)+(double)(raw.nsec)/1000000000.0 - initial;
        if((current-past) < limit){
            diff = 0.9*diff + 0.1*(current - past);
        }
    }
}

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

AccKalman::AccKalman(double dt_)
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
, coeF(1.0, dt_, -0.00001, 0.0)//internal state matrix
, coeB(0.0, gravity)//input matrix/vector
, coeG()      //state noise matrix
, coeH()      //measurement matrix
, coeR()      //covariance matrix
, coeQ()      //covariance matrix
, input(0.0)
, unit()
{
}
void AccKalman::predict(){
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
void AccKalman::update(){
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
void AccKalman::filter(Vector2& predicted, Vector2& measured, double& input_, double& dtime){
    vecZ = measured;
    input = input_;
    coeF.b = dtime;
    coeB.x = 0.0;//pow(dtime,2)/2;
    coeB.v = gravity;//dtime;
    predict();
    update();
    predicted = vecX_f;
}


LPF::LPF(){
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
LPF::LPF(int mode){
    if(mode==1){
        /*cut off freq = 0.1, stop freq = 5.0,samp freq=30.0, late=1,504ms*/
        k =    0.243813869568824587;
        b[0][0] =  -1.94989857144133194;
        b[0][1] =  0.951123341659861565;
        a[0][0] =  0.00125584551516228589;
        a[0][1] =  0.00251169103032457177;
        a[0][2] =  0.00125584551516228589;
    }else if(mode==2){
        /*cut off freq = 1.0, stop freq = 10.0,samp freq=30.0, late=160ms*/
        k = 0.194837660791046668;
        b[0][0] =  -1.50940768281959503;
        b[0][1] =  0.607994889837151442;
        a[0][0] =  0.126499166815709163;
        a[0][1] =  0.252998333631418326;
        a[0][2] =  0.126499166815709163;
    }else if(mode==3){
        /*cut off freq = 0.81, stop freq = 10,samp freq=100, late=200ms*/
        k =   0.235237134605256248;
        b[0][0] = -1.87840695649242306;
        b[0][1] = 0.885387197191676911;
        a[0][0] = 0.00741830229203298015;
        a[0][1] = 0.0148366045840659603;
        a[0][2] = 0.00741830229203298015;
    }else{
        /*cut off freq = 2.1, stop freq = 12.5,samp freq=32.2, late=80ms*/
        k = 0.154239871134214918;
        b[0][0] = -1.08138205505268603;
        b[0][1] = 0.386455883094752650;
        a[0][0] = 0.494479517194034046;
        a[0][1] = 0.988959034388068092;
        a[0][2] = 0.494479517194034046;
    }
    
    in = 0;
    out = 0;
    initialize = 0;
    for(int i=0;i<3;i++){
        x[i]=0;
    }
}
double LPF::filter(double data){
    if(initialize>0){
        x[0]=x[1]=x[2]=data;
        initialize--;
        printf("a\n");
    }
    in = data;
    x[2] = x[1];
    x[1] = x[0];
    x[0] = k*in - (b[0][0]*x[1] + b[0][1]*x[2]);
    out = a[0][0]*x[0] + a[0][1]*x[1] + a[0][2]*x[2];
    return out;
}

Ground_class::Ground_class(double tm_diff_)
: filter()
, tm(tm_diff_)
, kalman(tm_diff_)
{
    initial  = 0.0;
    current  = 0.0;
    past     = 0.0;
    velocity = 0.0;
    raw      = 0.0;
    raw_current = 0.0;
    raw_past = 0.0;
    raw_diff = 0.0;
    input = 0.0;
}

void Ground_class::update(double data, double roll, double pitch){
    tm.update();
    raw = data;
    double temp = data*cos(roll)*cos(pitch);
    if(initial == 0.0){
        initial = temp;
    }
    raw_past = raw_current;
    if(raw == 0.0){
        raw_current = raw_past;
    }else{
        raw_current = temp - initial;
    }
    
    if(raw_current < 0.0){
        raw_current = 0.001;
    }
    raw_diff = raw_current - raw_past;
    
    past = current;
    current = filter.filter(raw_current);
    velocity = (current - past)/tm.diff;
    measured.x = raw_current;
    measured.v = velocity;
    kalman.filter(predicted, measured, input, tm.diff);
}
