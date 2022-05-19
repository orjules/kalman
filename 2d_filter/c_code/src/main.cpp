#include<stdio.h>
#include <random>
#include"../../../libraries/BasicLinearAlgebra-3.6/BasicLinearAlgebra.h"

using namespace BLA;
using namespace std;

default_random_engine rng;

void print_measurements(float time, Matrix<2,1> actual, Matrix<2,1> erroneous){
    printf("%f, %f, %f, %f, %f\n", time, actual(0), actual(1), erroneous(0), erroneous(1));
}

Matrix<2,1> calculate_actual_measurements(float time){
    Matrix<2,1> z;
    z.Fill(0.0);

    if (time < 1 || (time>6 && time<7)){
        z(0) = 1.0; // first accelerate
    }else if ((time>4 && time<5) || (time>8 && time<9)){
        z(0) = -1.0;
    }else if (time>5 && time<6){
        z(1) = -90.0;
    }
    
    return z;
}

Matrix<2,1> calculate_erroneous_measurements(float time, float acc_error, float rot_error){
    Matrix<2,1> z = calculate_actual_measurements(time);

    normal_distribution<float> rand_acc(0.0, acc_error);
    normal_distribution<float> rand_rot(0.0, rot_error);

    z(0) = z(0) + rand_acc(rng);
    z(1) = z(1) + rand_rot(rng);
    
    return z;
}

int main (int argc, char *argv[]){
    float time = 0.0;
    float delta_t = 0.1;
    float acc_measurement_error = 0.2;
    float rot_measurement_error = 0.1;

    Matrix<2,1> z_actual;
    z_actual.Fill(0.0);
    Matrix<2,1> z_erroneous;
    z_erroneous.Fill(0.0);

    printf("Time, ActualAcc, ActualRot, ErroneousAcc, ErroneousRot\n");

    for (int i = 0; i < 101; i++){
        print_measurements(time, z_actual, z_erroneous);
        z_actual = calculate_actual_measurements(time);
        z_erroneous = calculate_erroneous_measurements(time, acc_measurement_error, rot_measurement_error);
        time += delta_t;
    }   
}