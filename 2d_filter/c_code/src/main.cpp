#include<stdio.h>
#include <random>
#include"../../../libraries/BasicLinearAlgebra-3.6/BasicLinearAlgebra.h"
#include"logger.h"

#define PI 3.14159

using namespace BLA;
using namespace std;

default_random_engine rng;


Matrix<3,1> calculate_actual_measurements(float time){
    Matrix<3,1> z;
    z.Fill(0.0);

    if (time<=1.0){
        z(1) = 1.0;
    }else if (time>2.0 && time<=3.0){
        z(1) = -1.0;
    }
    
    
    /*if (time>0 && time<=1){
        z(1) = 1.0;
    }else if (time>4 && time<=5){
        z(1) = -1.0;
    }else if (time>6 && time<=7){
        z(1) = 1.0;
    }else if (time>8 && time<=9){
        z(1) = -1.0;
    }else if (time>5 && time<=6){
        z(2) = - PI / 2;
    }*/
    
    return z;
}

Matrix<3,1> calculate_erroneous_measurements(float time, float acc_error, float rot_error){
    Matrix<3,1> z = calculate_actual_measurements(time);

    normal_distribution<float> rand_acc(0.0, acc_error);
    normal_distribution<float> rand_rot(0.0, rot_error);

    z(0) = z(0) + rand_acc(rng);
    z(1) = z(1) + rand_acc(rng);
    z(2) = z(2) + rand_rot(rng);
    
    return z;
}

Matrix<8,8> get_A_matrix(float delta_t, float phi){
    Matrix<8,8> A;
    A.Fill(0.0);

    float cos_phi = cos(phi);
    float sin_phi = sin(phi);

    A(0,0) = 1.0;
    A(0,2) = delta_t * cos_phi;
    A(0,3) = delta_t * (- sin_phi);
    A(0,4) = 0.5 * delta_t * delta_t * cos_phi;
    A(0,5) = 0.5 * delta_t * delta_t * (- sin_phi);
    A(1,1) = 1.0;
    A(1,2) = delta_t * sin_phi;
    A(1,3) = delta_t * cos_phi;
    A(1,4) = 0.5 * delta_t * delta_t * sin_phi;
    A(1,5) = 0.5 * delta_t * delta_t * cos_phi;
    A(2,2) = cos_phi;
    A(2,3) = - sin_phi;
    A(2,4) = delta_t * cos_phi;
    A(2,5) = delta_t * (- sin_phi);
    A(3,2) = sin_phi;
    A(3,3) = cos_phi;
    A(3,4) = delta_t * sin_phi;
    A(3,5) = delta_t * cos_phi;
    A(4,4) = cos_phi;
    A(4,5) = - sin_phi;
    A(5,4) = sin_phi;
    A(5,5) = cos_phi;
    A(6,6) = 1.0;
    A(6,7) = delta_t;
    A(7,7) = 1.0;

    return A;
}

Matrix<8,8> get_initial_P_matrix(){
    Matrix<8,8> P;
    P.Fill(0.0);    
    P(0,0) = 1.5;
    P(1,1) = 1.5;
    P(2,2) = 1.0;
    P(3,3) = 1.0;
    P(4,4) = 15.0;
    P(5,5) = 15.0;
    P(6,6) = 1.5;
    P(7,7) = 1.0;

    return P;
}

Matrix<3,8> get_H_matrix(){
    Matrix<3,8> H;
    H.Fill(0.0);

    H(0,4) = 1.0;
    H(1,5) = 1.0;
    H(2,7) = 1.0;

    return H;
}

Matrix<3,3> get_R_matrix(float error_ax, float error_ay, float error_rot){
    Matrix<3,3> R;
    R.Fill(0.0);
    R(0,0) = error_ax;
    R(1,1) = error_ay;
    R(2,2) = error_rot;
    return R;
}

Matrix<8,3> calculate_Kalman_gain(Matrix<8,8> P, Matrix<3,8> H, Matrix<3,3> R){
    Matrix<8,3> temp = P * ~H;
    Matrix<3,3> temp2 = H * temp + R;
    Invert(temp2);
    return temp * temp2;
}

int main (int argc, char *argv[]){
    float time = 0.0;
    float delta_t = 0.1;
    float acc_measurement_error = 0.1;
    float acc_uncertainty = 0.0001;
    float rot_measurement_error = 0.2;
    float rot_uncertainty = 1;

    LOGLEVEL log_level = PLOT;

    Matrix<8,1> x;
    x.Fill(0.0);
    Matrix<8,8> P = get_initial_P_matrix();
    Matrix<3,1> z_actual;
    z_actual.Fill(0.0);
    Matrix<3,1> z_erroneous;
    z_erroneous.Fill(0.0);
    Matrix<3,8> H = get_H_matrix();
    Matrix<3,3> R = get_R_matrix(acc_uncertainty, acc_uncertainty, rot_uncertainty);
    

    log_header(log_level);

    for (int i = 0; i < 51; i++){
        time += delta_t;
        log_time(time, log_level);

        // Prediction step
        Matrix<8,8> A = get_A_matrix(delta_t, x(6));

        log_given_A_x(A, x, log_level);
        x = A * x;
        log_result_x(x, log_level);

        log_given_A_P(A,P, log_level);
        P = A * P * ~A;
        log_result_P(P, log_level);
        

        // Calculate measurements
        z_actual = calculate_actual_measurements(time);
        z_erroneous = calculate_erroneous_measurements(time, acc_measurement_error, rot_measurement_error);
        log_measurements(time, z_actual, z_erroneous, acc_measurement_error, rot_measurement_error, log_level);
        

        // Correction step
        log_given_P_H_R(P,H,R, log_level);
        Matrix<8,3> K = calculate_Kalman_gain(P, H, R);
        log_result_K(K, log_level);

        log_given_x_K_z(x, K, z_actual, log_level);
        x = x + K * (z_actual - H * x);
        log_result_x(x, log_level);
        log_state(time, x, log_level);
        log_plot(time, x, z_actual, log_level);

        log_given_P_K_H(P,K,H, log_level);
        P = P - K * H * P; 
        log_result_P(P, log_level);
    }   
}