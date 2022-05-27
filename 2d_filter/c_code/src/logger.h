#include"../../../libraries/BasicLinearAlgebra-3.6/BasicLinearAlgebra.h"

using namespace BLA;

enum LOGLEVEL{
    DEBUG,
    PLOT
};

class logger{
private:
    LOGLEVEL level;
    void p_8_name(char name, float a, float b, float c, float d, float e, float f, float g, float h);
    void p_8(float a, float b, float c, float d, float e, float f, float g, float h);
    void p_3_name(char name, float a, float b, float c);
    void p_3(float a, float b, float c);
public:
    logger(LOGLEVEL log_level);
    /* For Debugging */
    void log_time(float time);
    // Prediction step
    void log_prediction();
    void log_given_A_x_P_Q(Matrix<8,8> A, Matrix<8,1> x, Matrix<8,8> P, Matrix<8,8> Q);
    void log_result_x_P(Matrix<8,1> x, Matrix<8,8> P);
    // Correction step
    void log_correction();
    void log_given_P_H_R(Matrix<8,8> P, Matrix<3,8> H, Matrix<3,3> R);
    void log_result_K(Matrix<8,3> K);
    void log_given_x_K_P_z(Matrix<8,1> x, Matrix<8,3> K, Matrix<8,8> P, Matrix<3,1> z);
    /* For Plotting */
    void log_header();
    void log_plot(float time, Matrix<8,1> state, Matrix<3,1> measurements, float acc_error, float rot_error, float Q_acc, float Q_rot);
};