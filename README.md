# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Structure

The main.cpp is the interface between the simulator and the pid class. It receives angle, crosstrack-error and speed from the simulator. 
Then, the crosstrack-error is used to PID-control the steering angle. The PID class is initialized with PID-Coefficients. 
Calculating the PID-errors in each timestep, it returns the steering angle. 

The parameters are tuned as follows: First, some p-value is guessed. The error value is 4 when the car is at the border of the road, then the steering angle should be 1. 
The parameter 0.2 for Kp seems to work fine on a full lap, but the car is oscillating heavily. The Kd value serves by dampening the oscillations. 
As long as disturbances lead to oscillation of the system, the d-part is too small, thus the system is unstable. 
The i-part sums up the entire error history. One issue in the given implementation is that the error is currently frame-rate dependend, since it gets summed at every step. 
If the i-part is too strong, the car stays on the one side of the road after a tight corner, because the integral has learned to steer into the tight corner. 
The system was tuned so the car stays in the middle after each corner. Yet, a small i-part helps in situations where a small p-part doesn't steer enough to get the corner and the car drifts towards the outside. 

Basically, both uncertainty of actuation and time delay lead to the necessity of a strong p-part. This p-part leads to an uncomfortable steering input, because it needs to react quickly and strongly to stay in lane. 
If the system cannot be improved either in actuation or time delay, the controller needs to look into the future to start steering before the car is off the desired track. 
Then, model-predictive control improves systems behavior. 

The result for the parameters Kp 0.15, Ki 0.0005 and Kd 7.0 is shown in the following video. The accelerator is fixed at 0.5 (50 %). On tight corners, the car just stays on track while achieving the best comfort 
possible with a given systems behavior.



![Alt Text](result.gif) 


## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

