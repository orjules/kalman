#include<stdio.h>
#include <random>
#include"../BasicLinearAlgebra-3.6/BasicLinearAlgebra.h"

#define GRAVITY -9.81

using namespace BLA;


void print_2by1(Matrix<2,1> matrix){
    printf("( %f )\n", matrix(0,0));
    printf("( %f )\n", matrix(1,0));
}

void print_2by2(Matrix<2,2> matrix){
    printf("( %f  %f )\n", matrix(0,0), matrix(0,1));
    printf("( %f  %f )\n", matrix(1,0), matrix(1,1));
}

Matrix<2,2> get_A_Matrix(float delta_t){
    Matrix<2,2> A;
    A.Fill(0.0);
    A(0,0) = 1.0;
    A(0,1) = delta_t;
    A(1,1) = 1.0;
    return A;
}

Matrix<2,1> predict_state(Matrix<2,1> last_x, Matrix<2,2> A, float delta_t){
    last_x = A * last_x;
    Matrix<2,1> B;
    B(0) = 0.5 * delta_t * delta_t;
    B(1) = delta_t;
    B = B * GRAVITY;
    last_x = last_x + B;
    return last_x;
}

Matrix<2,2> predict_uncertainty(Matrix<2,2> last_P, Matrix<2,2> A){
    last_P = A * last_P * ~A; // ~ is tranpose
    return A;
}

Matrix<2,1> calculate_KalmanGain(Matrix<2,2> P, Matrix<1,2> H, Matrix<1,1> R){
    Matrix<2,1> temp = P * ~H; // ~ is tranpose
    Matrix<1,1> temp2 = H * temp + R;
    Matrix<2,1> K = temp / temp2(0); // 2,1 divided by scalar value
    return K;
}

Matrix<2,1> correct_state(Matrix<2,1> pred_x, Matrix<2,1> gain, Matrix<1,1> measurement, Matrix<1,2> H){
    Matrix<1,1> diff = measurement - H * pred_x;
    Matrix<2,1> x = pred_x + gain * diff;
    return x;
}

Matrix<2,2> correct_uncertainty(Matrix<2,2> pred_P, Matrix<2,1> gain, Matrix<1,2> H){
    Matrix<2,2> P = pred_P - gain * H * pred_P;
    return P;
}

void print_row(Matrix<2,1> x, float time, float measured, float error, float uncertainty){
    printf("%f, %f, %f, %f, %f\n", time, x(0), measured, error, uncertainty);
}

int main (int argc, char *argv[]){
    // Set initial values
    Matrix<2,1> x; // state
    x(0) = 10.0; // 10m height
    x(1) = 10.0; // 10m/s upwards velocity
    Matrix<2,2> P; // state uncertainty
    P.Fill(0.0);
    P(0,0) = 25.0; // 25m^2 variance
    P(1,1) = 16.0; // 16m^2/s^2 variance
    Matrix<1,2> H; // Transforms state to measurement
    H(0) = 1;
    H(1) = 0;
    Matrix<1,1> z; // measurement
    float initial_uncertainty = 5.0;
    Matrix<1,1> R; // measurement uncertainty
    R(0) = initial_uncertainty; // meter 

    // Setup random number generator
    std::default_random_engine rng;
    std::normal_distribution<float> rand_time(0.01,0.005);
    float measurement_error = 1.0;
    std::normal_distribution<float> rand_measurement(0.0,measurement_error);

    printf("Time, Height, Measured, MeasurementError, InitialUncertainty\n");
    float time = 0;

    for (int i = 0; i < 1000; i++){
        float delta_t = rand_time(rng);
        Matrix<2,2> A = get_A_Matrix(delta_t);

        // Prediction Step
        x = predict_state(x, A, delta_t);
        P = predict_uncertainty(P, A);

        // Calculate measurement
        z(0) = x(0) + rand_measurement(rng); // value from sensor
        
        time += delta_t;
        print_row(x, time, z(0), measurement_error, initial_uncertainty);

        // Correction Step
        Matrix<2,1> K = calculate_KalmanGain(P, H, R);
        x = correct_state(x, K, z, H);
        P = correct_uncertainty(P, K, H);

        if (x(0) < 0){
            break;
        }
    }    
}