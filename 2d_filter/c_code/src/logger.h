#include"../../../libraries/BasicLinearAlgebra-3.6/BasicLinearAlgebra.h"

using namespace BLA;

/* For Debugging */

void log_time(float time);

// Prediction step
// Given: A and x => Result x
void log_given_A_x(Matrix<8,8> A, Matrix<8,1> x);
void log_result_x(Matrix<8,1> x);

// Given: A and P => Result P
void log_given_A_P(Matrix<8,8> A, Matrix<8,8> P);
void log_result_P(Matrix<8,8> P);


// Corrention step
// Given P, H and R => Result K
void log_given_P_H_R(Matrix<8,8> P, Matrix<3,8> H, Matrix<3,3> R);
void log_result_K(Matrix<8,3> K);

// Given x, K and z => Result x
void log_given_x_K_z(Matrix<8,1> x, Matrix<8,3> K, Matrix<3,1> z);

// Given P, H and K => Result P
void log_given_P_K_H(Matrix<8,8> P, Matrix<8,3> K, Matrix<3,8> H);



/* For Plotting */