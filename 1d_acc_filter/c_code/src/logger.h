#include"../../../libraries/BasicLinearAlgebra-3.6/BasicLinearAlgebra.h"

using namespace BLA;

enum LOGLEVEL{
    PLOT,
    DEBUG
};

// For Plotting
void log_header(LOGLEVEL level);
void log_plot(float time, Matrix<3,1> x, Matrix<1,1> z, float meas_err, float Q_acc, LOGLEVEL level);

// For Debugging
void log_time_header(float time, LOGLEVEL level);
void log_prediction(LOGLEVEL level);
void log_correction(LOGLEVEL level);
void log_given_A_x_P_Q(Matrix<3,3> A, Matrix<3,1> x, Matrix<3,3> P, Matrix<3,3> Q, LOGLEVEL level);
void log_result_x_P(Matrix<3,1> x, Matrix<3,3> P, LOGLEVEL level);
void log_given_P_H_R(Matrix<3,3> P, Matrix<1,3> H, Matrix<1,1> R, LOGLEVEL level);
void log_result_K(Matrix<3,1> K, LOGLEVEL level);
void log_given_x_K_z_P(Matrix<3,1> x, Matrix<3,1> K, Matrix<1,1> z, Matrix<3,3> P, LOGLEVEL level);