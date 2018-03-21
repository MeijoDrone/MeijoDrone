#include <stdio.h>
#include <float.h> // DBL_MIN
#include <math.h>
#include "sip_mavros/PID.h"

PID::PID()
	: p_gain(1.0)
	  , i_gain(0.0)
	  , d_gain(0.0)
	  , pre_d_gain(0.0)
	  , current_err(0.0)
	  , integrated_err(0.0)
	  , differentiated_err(0.0)
	  , pre_differentiated_err(0.0)
	  , raw_data()
	  , lowpassed_data()
	  , prev_lowpassed_err(0.0)
	  , ctrl_upper_limit(0.0)
	  , ctrl_lower_limit(0.0)
	  , offset(0.0)
	  , now(0)
	  , lpf_coefficients()
	  , LPF_BUFFSIZE(2)
{
}

PID::PID(double p_, double i_, double d_, double pre_d_
		, double ctrl_upper_limit_
		, double ctrl_lower_limit_
		, double offset_
		, double cutoff_freq_
		, double sample_freq_
		, double q_param_)
	: p_gain(p_)
		, i_gain(i_)
		, d_gain(d_)
		, pre_d_gain(pre_d_)
		, current_err(0.0)
		, integrated_err(0.0)
		, differentiated_err(0.0)
		, pre_differentiated_err(0.0)
		, raw_data()
		, lowpassed_data()
		, prev_lowpassed_err(0.0)
		, ctrl_upper_limit(ctrl_upper_limit_)
		, ctrl_lower_limit(ctrl_lower_limit_)
		, offset(offset_)
		, now(clock())
		, lpf_coefficients()
		, LPF_BUFFSIZE(2)
{
	for(size_t i = 0; i < LPF_BUFFSIZE; ++i)
	{
		raw_data.push_back(0.0);
		lowpassed_data.push_back(0.0);
	}

	const double PI = atan2(0.0, -1.0);
	double omega = 2.0 * PI * cutoff_freq_ / sample_freq_;
	double alpha = sin(omega) / (2.0 * q_param_);
	lpf_coefficients[0] = 1.0 + alpha;
	lpf_coefficients[1] = -2.0 * cos(omega);
	lpf_coefficients[2] = 1.0 - alpha;
	lpf_coefficients[3] = (1.0 - cos(omega)) / 2.0;
	lpf_coefficients[4] = 1.0 - cos(omega);
	lpf_coefficients[5] = (1.0 - cos(omega)) / 2.0;
}

void PID::lpf(double current)
{
	double val = lpf_coefficients[3] / lpf_coefficients[0] * current
		+ lpf_coefficients[4] / lpf_coefficients[0] * raw_data[0]
		+ lpf_coefficients[5] / lpf_coefficients[0] * raw_data[1]
		- lpf_coefficients[1] / lpf_coefficients[0] * lowpassed_data[0]
		- lpf_coefficients[2] / lpf_coefficients[0] * lowpassed_data[1];


	raw_data.push_front(current);
	raw_data.pop_back();

	lowpassed_data.push_front(val);
	lowpassed_data.pop_back();
}

void PID::clear_err()
{
	for(size_t i = 0; i < LPF_BUFFSIZE; ++i)
	{
		raw_data.push_back(0.0);
		lowpassed_data.push_back(0.0);
	}

	integrated_err = 0.0;
}

void PID::push_err(double target, double current, clock_t now_)
{
	double dt_sec = (double)(now_ - now) / (double)(CLOCKS_PER_SEC);
	if(dt_sec == 0.0) { dt_sec = DBL_MIN; }

	lpf(current);
	double err = target - current;
	double lowpassed_err = target - lowpassed_data.front();

	// Pre D
	pre_differentiated_err
		= (lowpassed_data.at(0) - lowpassed_data.at(1)) / dt_sec;

	// D
	differentiated_err
		= (lowpassed_err - prev_lowpassed_err) / dt_sec;

	// I
	integrated_err += err * dt_sec;

	// P
	current_err = err;

	now = now_;
	prev_lowpassed_err = lowpassed_err;
}

void PID::push_err(double target, double current, clock_t now_, char mode)
{
    double dt_sec = (double)(now_ - now) / (double)(CLOCKS_PER_SEC);
    if(dt_sec == 0.0) { dt_sec = DBL_MIN; }
    
    lpf(current);
    double err = target - current;
    double lowpassed_err = target - lowpassed_data.front();
    
    // Pre D
    pre_differentiated_err
    = (lowpassed_data.at(0) - lowpassed_data.at(1)) / dt_sec;
    
    // D
    differentiated_err
    = (lowpassed_err - prev_lowpassed_err) / dt_sec;
    
    if(mode == 1){
        
    }else{
        // I
        integrated_err += err * dt_sec;
    }
        
    // P
    current_err = err;
    
    now = now_;
    prev_lowpassed_err = lowpassed_err;
}

double PID::pop_ctrl()
{
	double u = p_gain * current_err
		+ i_gain * integrated_err
		+ d_gain * differentiated_err
		- pre_d_gain * pre_differentiated_err
		+ offset;
	if(u > ctrl_upper_limit){u = ctrl_upper_limit;}
	if(u < ctrl_lower_limit){u = ctrl_lower_limit;}
	return u;
}
