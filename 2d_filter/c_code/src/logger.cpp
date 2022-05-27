#include<stdio.h>
#include"logger.h"

logger::logger(LOGLEVEL log_level){
    level = log_level;
}

void logger::p_8_name(char name, float a, float b, float c, float d, float e, float f, float g, float h){
    printf("   %c: ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )",name,a,b,c,d,e,f,g,h);
}

void logger::p_8(float a, float b, float c, float d, float e, float f, float g, float h){
    printf("      ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )",a,b,c,d,e,f,g,h);
}

void logger::p_3_name(char name, float a, float b, float c){
    printf("   %c: ( %+1.3f, %+1.3f, %+1.3f )",name,a,b,c);
}

void logger::p_3(float a, float b, float c){
    printf("      ( %+1.3f, %+1.3f, %+1.3f )",a,b,c);
}

void logger::log_time(float time){
    if (level != DEBUG){ return; }

    printf("\n");
    for (int i = 0; i < 180; i++){
        printf("=");
    }
    printf("\n\nThe time is: %1.1f\n", time);
    for (int i = 0; i < 16; i++){
        printf("-");
    }
    printf("\n\n");
}

void logger::log_prediction(){
    if (level != DEBUG){ return; }
    printf("Prediction step\n");
}

void logger::log_given_A_x_P_Q(Matrix<8,8> A, Matrix<8,1> x, Matrix<8,8> P, Matrix<8,8> Q){
    if (level != DEBUG){ return; }
    printf("   Given:\n   ");
    p_8_name('A', A(0,0), A(0,1), A(0,2), A(0,3), A(0,4), A(0,5), A(0,6), A(0,7));
    printf("   x: ( %+1.3f )", x(0));
    printf("\n");
    for (int i = 1; i < 8; i++){
        printf("   ");
        p_8(A(i,0), A(i,1), A(i,2), A(i,3), A(i,4), A(i,5), A(i,6), A(i,7));
        printf("      ( %+1.3f )", x(i));
        printf("\n");
    }
    printf("\n   ");

    p_8_name('P', P(0,0), P(0,1), P(0,2), P(0,3), P(0,4), P(0,5), P(0,6), P(0,7));
    p_8_name('Q', Q(0,0), Q(0,1), Q(0,2), Q(0,3), Q(0,4), Q(0,5), Q(0,6), Q(0,7));
    printf("\n");
    for (int i = 1; i < 8; i++){
        printf("   ");
        p_8(P(i,0), P(i,1), P(i,2), P(i,3), P(i,4), P(i,5), P(i,6), P(i,7));
        p_8(Q(i,0), Q(i,1), Q(i,2), Q(i,3), Q(i,4), Q(i,5), Q(i,6), Q(i,7));
        printf("\n");
    }
}

void logger::log_result_x_P(Matrix<8,1> x, Matrix<8,8> P){
    if (level != DEBUG){ return; }
    printf("   Result:\n   ");
    printf("   x: ( %+1.3f )", x(0));
    p_8_name('P', P(0,0), P(0,1), P(0,2), P(0,3), P(0,4), P(0,5), P(0,6), P(0,7));
    printf("\n");
    for (int i = 1; i < 8; i++){
        printf("   ");
        printf("      ( %+1.3f )", x(i));
        p_8(P(i,0), P(i,1), P(i,2), P(i,3), P(i,4), P(i,5), P(i,6), P(i,7));
        printf("\n");
    }
}

void logger::log_correction(){
    if (level != DEBUG){ return; }
    printf("Correction step\n");
}

void logger::log_given_P_H_R(Matrix<8,8> P, Matrix<3,8> H, Matrix<3,3> R){
    if (level != DEBUG){ return; }
    printf("   Given:\n   ");
    p_8_name('P', P(0,0), P(0,1), P(0,2), P(0,3), P(0,4), P(0,5), P(0,6), P(0,7));
    p_3_name('H', H(0,0), H(0,1), H(0,2));
    p_3_name('R', R(0,0), R(0,1), R(0,2));
    printf("\n");
    for (int i = 1; i < 3; i++){
        printf("   ");
        p_8(P(i,0), P(i,1), P(i,2), P(i,3), P(i,4), P(i,5), P(i,6), P(i,7));
        p_3(H(i,0), H(i,1), H(i,2));
        p_3(R(i,0), R(i,1), R(i,2));
        printf("\n");
    }
    for (int i = 3; i < 8; i++){
        printf("   ");
        p_8(P(i,0), P(i,1), P(i,2), P(i,3), P(i,4), P(i,5), P(i,6), P(i,7));
        p_3(H(i,0), H(i,1), H(i,2));
        printf("\n");
    }
}
void logger::log_result_K(Matrix<8,3> K){
    if (level != DEBUG){ return; }
    printf("   Result:\n   ");
    p_3_name('K', K(0,0), K(0,1), K(0,2));
    printf("\n");
    for (int i = 1; i < 8; i++){
        printf("   ");
        p_3(K(i,0), K(i,1), K(i,2));
        printf("\n");
    }

}
void logger::log_given_x_K_P_z(Matrix<8,1> x, Matrix<8,3> K, Matrix<8,8> P, Matrix<3,1> z){
    if (level != DEBUG){ return; }
    printf("   Given:\n   ");
    printf("   x: ( %+1.3f )", x(0));
    p_3_name('K', K(0,0), K(0,1), K(0,2));
    p_8_name('P', P(0,0), P(0,1), P(0,2), P(0,3), P(0,4), P(0,5), P(0,6), P(0,7));
    printf("   z: ( %+1.3f )", z(0));
    printf("\n");
    for (int i = 1; i < 3; i++){
        printf("   ");
        printf("      ( %+1.3f )", x(i));
        p_3(K(i,0), K(i,1), K(i,2));
        p_8(P(i,0), P(i,1), P(i,2), P(i,3), P(i,4), P(i,5), P(i,6), P(i,7));
        printf("      ( %+1.3f )", z(i));
        printf("\n");
    }
    for (int i = 3; i < 8; i++){
        printf("   ");
        printf("      ( %+1.3f )", x(i));
        p_3(K(i,0), K(i,1), K(i,2));
        p_8(P(i,0), P(i,1), P(i,2), P(i,3), P(i,4), P(i,5), P(i,6), P(i,7));
        printf("\n");
    }
}


void logger::log_header(){
    if (level != PLOT){ return; }
    printf("Time, ");
    printf("PosX, PosY, ");
    printf("VelX, VelY, ");
    printf("AccX, AccY, ");
    printf("Rot, RotSpeed, ");
    printf("MeasAccX, MeasAccY, MeasRot, ");
    printf("AccError, RotError, ");
    printf("Q_acc, Q_rot\n");
}
void logger::log_plot(float time, Matrix<8,1> state, Matrix<3,1> measurements, float acc_error, float rot_error, float Q_acc, float Q_rot){
    if (level != PLOT){ return; }
    printf("%f, ", time);
    printf("%f, %f, ", state(0), state(1));
    printf("%f, %f, ", state(2), state(3));
    printf("%f, %f, ", state(4), state(5));
    printf("%f, %f, ", state(6), state(7));
    printf("%f, %f, %f, ", measurements(0), measurements(1), measurements(2));
    printf("%f, %f, ", acc_error, rot_error);
    printf("%f, %f\n", Q_acc, Q_rot);
}