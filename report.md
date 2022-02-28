### Solution

PID (proportional integral derivative) controllers use a control loop feedback mechanism to control process variables. While optimizing the PID parameter, the optimal values were found by trying first the P, then the I and then the D values one by one. In the simulation, the reactions of the vehicle were monitored.

Due to insufficient hardware for simulation, an application was developed on the remote desktop provided by UDACITY. The results are given below. </br>
[pid_test](https://www.youtube.com/watch?v=PPTg27vqDOs&ab_channel=MelikeTanr%C4%B1kulu "pid")

### Evaluation

A PID controller is implemented and integrated into the provided framework for throttle and steering control. Several fixes are added to the framework and simulation client to make the control smoother and more stable. PID controller (proportional–integral–derivative controller) parameters are handled separately for steering and throttle. Errors are also calculated separately. I tuned the parameters for the PID by observing the responses. When calculating the error, the yaw angle of the vehicle and the closest x and y points to the vehicle in the simulation and where the vehicle is at x and y were taken as reference.

The following figure shows the values in case of the simulation, the reference speed is calculated by the behavior planner. The x axis shows iterations. It can be seen that it takes a long time to reach the desired speed (the controller is damped) and even despite this, some oscillation is clearly visible.  It can be seen that initially the error is reduced quickly (caused by the proportional term), but then the equalibrium is reached slowly - this is caused by the slow buildup of the integral term.

<img src="/img/throttleData.png" alt="throttleData"/>

The Figure below shows the steering control error and its output in a scene with obstacles. There are three parts in the timeline where the error is huge, these are the 3 moments when the car runs through obstacles and has to change lanes. Part of the error here may be due to latency or other incompatibilities between the controller and simulation - for example, the root cause may be that the controller is planning too far ahead (takes the last waypoint).

<img src="/img/steerData.png" alt="throttleData"/>






