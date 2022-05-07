// integrates the path of the planet and writes the history to the screen
#include "lorenz.H"
#include <fstream>


int main() {
  
    double tmax = 100.0;
    double dt = 0.0001;
    double rho = 28.0;
    double sigma = 10.0;
    double beta = 8/3;

    auto history = integrate_rk2(sigma, rho, beta, tmax, dt, 1.0, 0.0, 0.0);

    write_history(history, "motion_28_10_8over3_100.txt");

    history = integrate_rk2(sigma, rho, beta, tmax, dt, 0.9, 0.0, 0.0);

    write_history(history, "motion_28_10_8over3_0p900.txt");

    history = integrate_rk2(sigma, rho, beta, tmax, dt, 0.75, 0.0, 0.0);

    write_history(history, "motion_28_10_8over3_0p7500.txt");

    history = integrate_rk2(sigma, rho, beta, tmax/100, dt, 0.0, 0.0, 1.0);

    write_history(history, "motion_28_10_8over3_001.txt");

    rho = 27.9;

    history = integrate_rk2(sigma, rho, beta, tmax, dt, 1.0, 0.0, 0.0);

    write_history(history, "motion_27p9_10_8over3_100.txt");
    
    return 0;
}
