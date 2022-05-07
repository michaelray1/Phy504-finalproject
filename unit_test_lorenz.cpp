// Unit test for Lorenz system integrator

#include "lorenz.H"
#include <iostream>
#include <math.h>
#include <cassert>
#include <fstream>

int main() {

    double tmax = 1.0;
    double dt = 0.0001;
    double rho = 28.0;
    double sigma = 10.0;
    double beta = 8/3;
    double tol = 1.e-8;

    auto history = integrate_rk2(sigma, rho, beta, tmax, dt, 0.0, 0.0, 1.0);

    write_history(history, "motion_28_10_8over3_100.txt");

    std::fstream file;
    file.open("motion_28_10_8over3_001.txt", std::ios::in);
    double data[10002][7];
    if (file.is_open()){
      for(int row = 0; row < 10002; row++) {
        for(int column = 0; column < 7; column++){
          file >> data[row][column];
        }}
    }
    file.close();

    // Assert that difference between analytic solution and integrated solution at t=1.0 are within tolerance
    assert(data[10001][4] - exp(-0.0001*beta) < tol);

    std::cout << "All tests passed!" << std::endl;
    
    return 0;
}
  
