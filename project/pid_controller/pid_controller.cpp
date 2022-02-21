
#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
  Kp = Kpi;
  Ki = Kii;
  Kd = Kdi;

  outputMax = output_lim_maxi;
  outputMin = output_lim_mini;

  Error_p = 0.0;
  Error_i = 0.0;
  Error_d = 0.0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
   if(deltaTime == 0) {
      Error_d = 0;
   } else {
      Error_d = (cte - Error_p) / deltaTime;
   }
   Error_p= cte;
   Error_i= cte * deltaTime;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
   double control_output = Kp * Error_p + Ki * Error_i +Kd * Error_d;
   control_output = min(control_output, outputMax);
   control_output = max(control_output, outputMin);
   return control_output;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
   deltaTime = new_delta_time;
   return deltaTime;
}