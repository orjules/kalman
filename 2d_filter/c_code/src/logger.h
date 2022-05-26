#include"../../../libraries/BasicLinearAlgebra-3.6/BasicLinearAlgebra.h"

using namespace BLA;

enum LOGLEVEL{
    DEBUG,
    MEASUREMENT,
    STATE,
    PLOT
};

/* For Debugging */

void log_time(float time, LOGLEVEL level);

// Prediction step
// Given: A and x => Result x
void log_given_A_x(Matrix<8,8> A, Matrix<8,1> x, LOGLEVEL level);
void log_result_x(Matrix<8,1> x, LOGLEVEL level);

// Given: A and P => Result P
void log_given_A_P(Matrix<8,8> A, Matrix<8,8> P, LOGLEVEL level);
void log_result_P(Matrix<8,8> P, LOGLEVEL level);


// Corrention step
// Given P, H and R => Result K
void log_given_P_H_R(Matrix<8,8> P, Matrix<3,8> H, Matrix<3,3> R, LOGLEVEL level);
void log_result_K(Matrix<8,3> K, LOGLEVEL level);

// Given x, K and z => Result x
void log_given_x_K_z(Matrix<8,1> x, Matrix<8,3> K, Matrix<3,1> z, LOGLEVEL level);

// Given P, H and K => Result P
void log_given_P_K_H(Matrix<8,8> P, Matrix<8,3> K, Matrix<3,8> H, LOGLEVEL level);



/* For Plotting */

void log_header(LOGLEVEL level);

void log_measurements(float time, Matrix<3,1> actual, Matrix<3,1> erroneous, float acc_error, float rot_error, LOGLEVEL level);

void log_state(float time, Matrix<8,1> state, LOGLEVEL level);

void log_plot(float time, Matrix<8,1> state, Matrix<3,1> measurements, LOGLEVEL level);