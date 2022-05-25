#include<stdio.h>
#include"logger.h"

void log_time(float time){
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

void log_given_A_x(Matrix<8,8> A, Matrix<8,1> x){
    printf("Prediction step\n");
    printf("   Given:\n");
    printf("       A: ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )   x: ( %+1.3f )\n", A(0,0), A(0,1), A(0,2), A(0,3), A(0,4), A(0,5), A(0,6), A(0,7), x(0));
    for (int i = 1; i < 8; i++){
        printf("          ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )      ( %+1.3f )\n", A(i,0), A(i,1), A(i,2), A(i,3), A(i,4), A(i,5), A(i,6), A(i,7), x(i));
    }
}

void log_result_x(Matrix<8,1> x){
    printf("   Result:\n");
    printf("      x: ( %+1.3f )\n", x(0));
    for (int i = 1; i < 8; i++){
        printf("         ( %+1.3f )\n", x(0));
    }
}

void log_given_A_P(Matrix<8,8> A, Matrix<8,8> P){
    printf("   Given:\n");
    printf("       A: ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )   P: ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )\n", A(0,0), A(0,1), A(0,2), A(0,3), A(0,4), A(0,5), A(0,6), A(0,7), P(0,0), P(0,1), P(0,2), P(0,3), P(0,4), P(0,5), P(0,6), P(0,7));
    for (int i = 1; i < 8; i++){
        printf("          ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )      ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )\n", A(i,0), A(i,1), A(i,2), A(i,3), A(i,4), A(i,5), A(i,6), A(i,7), P(i,0), P(i,1), P(i,2), P(i,3), P(i,4), P(i,5), P(i,6), P(i,7));
    }
}
void log_result_P(Matrix<8,8> P){
    printf("   Result:\n");
    printf("       P: ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )\n", P(0,0), P(0,1), P(0,2), P(0,3), P(0,4), P(0,5), P(0,6), P(0,7));
    for (int i = 1; i < 8; i++){
        printf("          ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )\n", P(i,0), P(i,1), P(i,2), P(i,3), P(i,4), P(i,5), P(i,6), P(i,7));
    }
}

void log_given_P_H_R(Matrix<8,8> P, Matrix<3,8> H, Matrix<3,3> R){
    for (int i = 0; i < 180; i++){
        printf("-");
    }
    printf("\nCorrection step\n");
    printf("   Given:\n");
    printf("       P: ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )   H: ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )   R: ( %+1.3f, %+1.3f, %+1.3f )\n", P(0,0), P(0,1), P(0,2), P(0,3), P(0,4), P(0,5), P(0,6), P(0,7), H(0,0), H(0,1), H(0,2), H(0,3), H(0,4), H(0,5), H(0,6), H(0,7), R(0,0), R(0,1), R(0,2));
    for (int i = 1; i < 3; i++){
        printf("          ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )      ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )      ( %+1.3f, %+1.3f, %+1.3f )\n", P(i,0), P(i,1), P(i,2), P(i,3), P(i,4), P(i,5), P(i,6), P(i,7), H(i,0), H(i,1), H(i,2), H(i,3), H(i,4), H(i,5), H(i,6), H(i,7), R(i,0), R(i,1), R(i,2));
    }
    for (int i = 3; i < 8; i++){
        printf("          ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )\n", P(i,0), P(i,1), P(i,2), P(i,3), P(i,4), P(i,5), P(i,6), P(i,7));
    }
}
void log_result_K(Matrix<8,3> K){
    printf("   Result:\n");
    printf("       K: ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )\n", K(0,0), K(0,1), K(0,2), K(0,3), K(0,4), K(0,5), K(0,6), K(0,7));
    for (int i = 1; i < 3; i++){
        printf("          ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )\n", K(i,0), K(i,1), K(i,2), K(i,3), K(i,4), K(i,5), K(i,6), K(i,7));
    }
}

void log_given_x_K_z(Matrix<8,1> x, Matrix<8,3> K, Matrix<3,1> z){
    printf("   Given:\n");
    printf("      x: ( %+1.3f )   K: ( %+1.3f, %+1.3f, %+1.3f )   z: ( %+1.3f )\n", x(0), K(0,0), K(0,1), K(0,2), z(0));
    for (int i = 1; i < 3; i++){
        printf("         ( %+1.3f )      ( %+1.3f, %+1.3f, %+1.3f )      ( %+1.3f )\n", x(i), K(i,0), K(i,1), K(i,2), z(i));
    }
    for (int i = 3; i < 8; i++){
        printf("         ( %+1.3f )      ( %+1.3f, %+1.3f, %+1.3f )\n", x(i), K(i,0), K(i,1), K(i,2));
    }
}

void log_given_P_K_H(Matrix<8,8> P, Matrix<8,3> K, Matrix<3,8> H){
    printf("   Given:\n");
    printf("       P: ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )   K: ( %+1.3f, %+1.3f, %+1.3f )   H: ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )\n", P(0,0), P(0,1), P(0,2), P(0,3), P(0,4), P(0,5), P(0,6), P(0,7), K(0,0), K(0,1), K(0,2), H(0,0), H(0,1), H(0,2), H(0,3), H(0,4), H(0,5), H(0,6), H(0,7));
    for (int i = 1; i < 3; i++){
        printf("          ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )      ( %+1.3f, %+1.3f, %+1.3f )      ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )\n", P(i,0), P(i,1), P(i,2), P(i,3), P(i,4), P(i,5), P(i,6), P(i,7), K(i,0), K(i,1), K(i,2), H(i,0), H(i,1), H(i,2), H(i,3), H(i,4), H(i,5), H(i,6), H(i,7));
    }
    for (int i = 3; i < 8; i++){
        printf("          ( %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f, %+1.3f )      ( %+1.3f, %+1.3f, %+1.3f )\n", P(i,0), P(i,1), P(i,2), P(i,3), P(i,4), P(i,5), P(i,6), P(i,7), K(i,0), K(i,1), K(i,2));
    }
}