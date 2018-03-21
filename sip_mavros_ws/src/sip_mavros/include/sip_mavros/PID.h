#include <stddef.h> // size_t
#include <deque>
#include <time.h> // clock_t

class PID
{
	public:
		double p_gain;
		double i_gain;
		double d_gain;
		double pre_d_gain;

		double current_err;
		double integrated_err;
		double differentiated_err;
		double pre_differentiated_err;

		std::deque<double> raw_data;
		std::deque<double> lowpassed_data;
		double prev_lowpassed_err;

		double ctrl_upper_limit;
		double ctrl_lower_limit;
		double offset;
		clock_t now;
		double lpf_coefficients[6];
		size_t LPF_BUFFSIZE;

		PID();
		PID(double p_, double i_, double d_, double pre_d_
				, double ctrl_upper_limit_
				, double ctrl_lower_limit_
				, double offset_
				, double cutoff_freq_
				, double sample_freq_
				, double q_param_);
		void lpf(double current);
		void clear_err();
        void push_err(double target, double current, clock_t now_);
		void push_err(double target, double current, clock_t now_, char mode);
		double pop_ctrl();
		void reset_clock(){now = clock();}
};
