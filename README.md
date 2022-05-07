# Phy504-finalproject

This repository contains a few files for analyzing and visualizing the dynamics of the Lorenz system. These are listed with their function below.

compute_motion.cpp - This is the file which contains our main function. Right now, it contains a few different experimental setups (different values for rho, sigma, beta and different initial conditions). The setups can easily be changed by changing the main function.

Lorenz.H - This is a header file containing the actual integrator that integrates the Lorenz system equations of motion. It also contains functions for writing data to files. The integrator uses 2nd order Runge-Kutta to integrate the equations of motion.

unit_test_lorenz.cpp - This file is used for testing the convergence of the integrator. What it does is tests an integrated solution against an analystic solution for x0=y0=0. In this case, x(t) = x0, y(t) = y0 and z(t) = z0 exp(-beta t). We test to see if the integrated solution is within a given tolerance of this analytic solution and return 0 (as well as a "tests passed" message) if the tests have been passed.

Lorenz System Dynamics.ipynb - This is a jupyter notebook that contains a very short overview of the output of the code. It shows a couple graphs of the result of integrating the equations of motion and it has a short discussion of the results.

makefile - This file compiles all our code. Run "make all" to compile the compute_motion.cpp. Run "make test" to compile the unit_test_lorenz.cpp file, which will create an executable called "test".
