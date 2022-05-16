#include<stdio.h>
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
    last_P = A * last_P * ~A;
    return A;
}

int main (int argc, char *argv[]){
    // Set initial values
    Matrix<2,1> x;
    x(0) = 10.0; // 10m height
    x(1) = 10.0; // 10m/s upwards velocity
    Matrix<2,2> P;
    P.Fill(0.0);
    P(0,0) = 25.0; // 25m^2 variance
    P(1,1) = 16.0; // 16m^2/s^2 variance

    for (int i = 0; i < 1; i++){
        float delta_t = 0.1; // TODO calculate randomly
        Matrix<2,2> A = get_A_Matrix(delta_t);
        // Prediction Step
        x = predict_state(x, A, delta_t);
        P = predict_uncertainty(P, A);

        // Calculate measurement
        // Correction Step
    }
    
}



