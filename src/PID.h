#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
	
  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double KpIn, double KiIn, double KdIn);

  /*
  * Update the PID error variables given cross track error.
  */
  void update(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
