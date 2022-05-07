// Header file that implements integrate function to integrate the equations of motion of the Lorenz system
#ifndef LORENZ_H
#define LORENZ_H


#include <vector>
#include <iostream>
#include <string>
#include <fstream>


struct State {
    double t;
    double x;
    double y;
    double z;
    double xdot;
    double ydot;
    double zdot;
};



void write_history(const std::vector<State>& history, std::string file) {

  std::fstream motion;
  motion.open(file, std::ios::out);

    for (auto o : history) {

      motion << o.t
            << "," << o.x
            << "," << o.y
  	    << "," << o.z
            << "," << o.xdot
            << "," << o.ydot
	    << "," << o.zdot << std::endl;

    }

  motion.close();

}



std::vector<State> integrate_rk2(const double sigma, const double rho, const double beta, const double tmax, const double dt, const double x0, const double y0, const double z0) {
    // declare the history of the orbit
    std::vector<State> history{};

    // set initial conditions
    State midpt_state{};
    State state{};

    state.t = 0.0;
    state.x = x0;
    state.y = y0;
    state.z = z0;
    state.xdot = 0.0;
    state.ydot = 0.0;
    state.zdot=0.0;

    history.push_back(state);

    // integration loop
    while (state.t < tmax) {
      // get the derivatives at t0
      state.xdot = sigma*(state.y-state.x);
      state.ydot = state.x*(rho-state.z)-state.y;
      state.zdot = state.x*state.y - beta*state.z;

      // Calculate estimate to midpoint state
      midpt_state.t = state.t + 0.5 * dt;
      midpt_state.x = state.x + 0.5 * dt * state.xdot;
      midpt_state.y = state.y + 0.5 * dt * state.ydot;
      midpt_state.z = state.z + 0.5 * dt * state.zdot;
      
      midpt_state.xdot = sigma*(midpt_state.y - midpt_state.x);
      midpt_state.ydot = midpt_state.x * (rho - midpt_state.z) - midpt_state.y;
      midpt_state.zdot = midpt_state.x * midpt_state.y - beta * midpt_state.z;

      // Update state using midpoint state
      state.t += dt;
      state.x += midpt_state.xdot * dt;
      state.y += midpt_state.ydot * dt;
      state.z += midpt_state.zdot * dt;
      
      history.push_back(state);
    }

    
    return history;
}



#endif
