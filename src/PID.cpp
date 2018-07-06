#include "PID.h"
#include <math.h>
#include <time.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double KpIn, double KiIn, double KdIn) {
	Kp = KpIn;
	Ki = KiIn;
	Kd = KdIn;
	p_error=0;
	i_error=0;
	d_error=0;
}

void PID::update(double cte) {
	//compute error components
	d_error=cte-p_error;  //current - last. Simple equation, filtering may be necessary
	p_error=cte;
	//problematic because it's relative to frame rate
	i_error+=cte;
	}

double PID::TotalError() {
	return -Kp*p_error-Ki*i_error-Kd*d_error;
}

