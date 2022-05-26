#include<stdio.h>
#include <random>
#include"../../../libraries/BasicLinearAlgebra-3.6/BasicLinearAlgebra.h"
#include"logger.h"

using namespace BLA;

Matrix<3,3> get_A_matrix(float dt){
    Matrix<3,3> A;
    A.Fill(0.0);
    A(0,0) = 1.0;
    A(0,1) = dt;
    A(0,2) = 0.5 * dt * dt;
    A(1,1) = 1.0;
    A(1,2) = dt;
    A(2,2) = 1.0;
}

Matrix<1,1> get_measurement(float time){
    Matrix<1,1> z;
    if (time < 1.0){
        z(0) = 1.0;
    }else if (time < 2.0){
        z(0) = 0.0;
    }else if (time < 3.0){
        z(0) = -1.0;
    }else{
        z(0) = 0.0;
    }
    return z;
}

Matrix<3,1> calculate_Kalman_gain(Matrix<3,3> P, Matrix<1,3> H, Matrix<1,1> R){
    Matrix<3,1> dividend = P * ~H;
    Matrix<1,1> divisor = H * dividend + R;
    Invert(divisor);
    return dividend * divisor;
}

int main (int argc, char *argv[]){
    float time = 0.0;
    const float delta_t = 0.5;
    const float meas_error = 0.1;

    LOGLEVEL log_level = DEBUG;
    Matrix<3,1> x;
    x.Fill(0.0);
    Matrix<3,3> A = get_A_matrix(delta_t);
    Matrix<3,3> P;
    P.Fill(0.0);
    P(0,0) = 0.5;
    P(1,1) = 0.5;
    P(2,2) = 0.5;
    Matrix<1,1> z;
    Matrix<1,3> H;
    H.Fill(0.0);
    H(2) = 1.0;
    Matrix<1,1> R;
    R(0,0) = meas_error;
    Matrix<3,1> K;

    log_header(log_level);

    for (int i = 0; i < 8; i++){
        time += delta_t;

        log_time_header(time, log_level);
        log_prediction(log_level);

        log_given_A_x_P(A,x,P, log_level);
        x = A * x;
        P = A * P * ~A;
        log_result_x_P(x,P,log_level);

        log_correction(log_level);

        log_given_P_H_R(P,H,R,log_level);
        K = calculate_Kalman_gain(P, H, R);
        log_result_K(K,log_level);
        
        z = get_measurement(time);

        log_given_x_K_z_P(x,K,z,P,log_level);
        x = x + K * (z - H * x);
        P = P - K * H * P;
        log_result_x_P(x,P,log_level);

        log_plot(time, x, z, log_level);
    }
    
}