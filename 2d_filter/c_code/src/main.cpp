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

Matrix<8,8> get_Q_matrix(float Q_acc, float Q_rot){
    Matrix<8,8> Q;
    Q.Fill(0.0);
    Q(4,4) = Q_acc;
    Q(5,5) = Q_acc;
    Q(7,7) = Q_rot;
    return Q;
}

Matrix<8,3> calculate_Kalman_gain(Matrix<8,8> P, Matrix<3,8> H, Matrix<3,3> R){
    Matrix<8,3> temp = P * ~H;
    Matrix<3,3> temp2 = H * temp + R;
    Invert(temp2);
    return temp * temp2;
}

int main (int argc, char *argv[]){
    float time = 0.0;
    const float delta_t = 0.1;
    const float acc_meas_error = 0.1;
    const float rot_meas_error = 0.2;
    const float Q_acc = 0.5;
    const float Q_rot = 1.0;

    logger lg = logger(PLOT);

    Matrix<8,1> x;
    x.Fill(0.0);
    Matrix<8,8> P = get_initial_P_matrix();
    Matrix<3,1> z;
    z.Fill(0.0);
    Matrix<3,8> H = get_H_matrix();
    Matrix<3,3> R = get_R_matrix(acc_meas_error, acc_meas_error, rot_meas_error);

    Matrix<8,8> Q = get_Q_matrix(Q_acc, Q_rot);
    

    lg.log_header();

    for (int i = 0; i < 51; i++){
        time += delta_t;
        lg.log_time(time);

        // Prediction step
        Matrix<8,8> A = get_A_matrix(delta_t, x(6));


        lg.log_given_A_x_P_Q(A, x, P, Q);
        x = A * x;
        P = A * P * ~A + Q;
        lg.log_result_x_P(x,P);
        

        // Calculate measurements
        z = calculate_actual_measurements(time);
        // z = calculate_erroneous_measurements(time, acc_meas_error, rot_meas_error);
 
        // Correction step
        lg.log_given_P_H_R(P, H, R);
        Matrix<8,3> K = calculate_Kalman_gain(P, H, R);
        lg.log_result_K(K);
        
        lg.log_given_x_K_P_z(x,K,P,z);
        x = x + K * (z - H * x);
        P = P - K * H * P; 
        lg.log_result_x_P(x,P);

        lg.log_plot(time, x, z, acc_meas_error, rot_meas_error, Q_acc, Q_rot);
    }   
}