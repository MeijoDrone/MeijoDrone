//
//  kalman_filter.h
//  
//
//  Created by IKEDA Takahiro on 2017/07/28.
//
//

#ifndef kalman_filter_h
#define kalman_filter_h

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

#endif /* kalman_filter_h */
