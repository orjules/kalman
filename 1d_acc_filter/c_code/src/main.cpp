#include<stdio.h>
#include <random>
#include"../../../libraries/BasicLinearAlgebra-3.6/BasicLinearAlgebra.h"
#include"logger.h"

using namespace BLA;
using namespace std;

default_random_engine rng;

Matrix<3,3> get_A_matrix(float dt){
    Matrix<3,3> A;
    A.Fill(0.0);
    A(0,0) = 1.0;
    A(0,1) = dt;
    A(0,2) = 0.5 * dt * dt;
    A(1,1) = 1.0;
    A(1,2) = dt;
    A(2,2) = 1.0;
    return A;
}

Matrix<3,3> get_Q_matrix(float Q_acc){
    // Process noise
    Matrix<3,3> Q;
    Q.Fill(0.0);
    Q(2,2) = Q_acc;
    return Q;
}

Matrix<3,1> calculate_Kalman_gain(Matrix<3,3> P, Matrix<1,3> H, Matrix<1,1> R){
    Matrix<3,1> dividend = P * ~H;
    Matrix<1,1> divisor = H * dividend + R;
    Invert(divisor);
    return dividend * divisor;
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

Matrix<1,1> get_erroneous_measurements(float time, float meas_error){
    Matrix<1,1> z = get_measurement(time);
    normal_distribution<float> rand_acc(0.0, meas_error);
    z(0) = z(0) + rand_acc(rng);
    return z;
}


int main (int argc, char *argv[]){
    float time = 0.0;
    const float delta_t = 0.1;
    const float meas_error = 0.1;
    const float Q_acc = 0.03;

    LOGLEVEL log_level = PLOT;
    Matrix<3,1> x;
    x.Fill(0.0);
    Matrix<3,3> A = get_A_matrix(delta_t);
    Matrix<3,3> P;
    P.Fill(0.0);
    P(0,0) = 3.5;
    P(1,1) = 3.5;
    P(2,2) = 15.0;
    Matrix<1,1> z;
    Matrix<1,3> H;
    H.Fill(0.0);
    H(0,2) = 1.0;
    Matrix<1,1> R;
    R(0,0) = meas_error;
    Matrix<3,1> K;

    Matrix<3,3> Q = get_Q_matrix(Q_acc);

    log_header(log_level);

    for (int i = 0; i < 41; i++){
        time += delta_t;

        log_time_header(time, log_level);
        log_prediction(log_level);

        log_given_A_x_P_Q(A,x,P,Q,log_level);
        x = A * x;
        P = A * P * ~A + Q;
        log_result_x_P(x,P,log_level);

        log_correction(log_level);

        log_given_P_H_R(P,H,R,log_level);
        K = calculate_Kalman_gain(P, H, R);
        log_result_K(K,log_level);
        
        // z = get_measurement(time);
        z = get_erroneous_measurements(time, meas_error);

        log_given_x_K_z_P(x,K,z,P,log_level);
        x = x + K * (z - H * x);
        P = P - K * H * P;
        log_result_x_P(x,P,log_level);

        log_plot(time, x, z, meas_error, Q_acc, log_level);
    }
    
}