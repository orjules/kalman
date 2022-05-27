#include"logger.h"

void log_header(LOGLEVEL level){
    if (level != PLOT){ return; }
    printf("Time, Direction, Velocity, Acceleration, Measurement\n");
}

void log_plot(float time, Matrix<3,1> x, Matrix<1,1> z, LOGLEVEL level){
    if (level != PLOT){ return; }
    printf("%f, %f, %f, %f, %f\n", time, x(0), x(1), x(2), z(0));
}

void log_time_header(float time, LOGLEVEL level){
    if (level != DEBUG){ return; }
    printf("\n");
    for (int i = 0; i < 90; i++){
        printf("=");
    }
    printf("\n\nThe time is: %1.2f\n", time);
    for (int i = 0; i < 16; i++){
        printf("-");
    }
    printf("\n\n");
}

void log_prediction(LOGLEVEL level){
    if (level != DEBUG){ return; }
    printf("Prediction step\n");
}

void log_correction(LOGLEVEL level){
    if (level != DEBUG){ return; }
    printf("Correction step\n");
}

void log_given_A_x_P_Q(Matrix<3,3> A, Matrix<3,1> x, Matrix<3,3> P, Matrix<3,3> Q, LOGLEVEL level){
    if (level != DEBUG){ return; }
    printf("   Given:\n");
    printf("   A: ( %1.3f, %1.3f, %1.3f )   x: ( %1.3f )   P: ( %1.3f, %1.3f, %1.3f )   Q: ( %1.3f, %1.3f, %1.3f )\n", A(0,0), A(0,1), A(0,2), x(0), P(0,0), P(0,1), P(0,2), Q(0,0), Q(0,1), Q(0,2));
    for (int i = 1; i < 3; i++)
    {
        printf("      ( %1.3f, %1.3f, %1.3f )      ( %1.3f )      ( %1.3f, %1.3f, %1.3f )      ( %1.3f, %1.3f, %1.3f )\n", A(i,0), A(i,1), A(i,2), x(i), P(i,0), P(i,1), P(i,2), Q(i,0), Q(i,1), Q(i,2));
    }
}

void log_result_x_P(Matrix<3,1> x, Matrix<3,3> P, LOGLEVEL level){
    if (level != DEBUG){ return; }
    printf("   Result:\n");
    printf("   x: ( %1.3f )   P: ( %1.3f, %1.3f, %1.3f )\n", x(0), P(0,0), P(0,1), P(0,2));
    for (int i = 1; i < 3; i++)
    {
        printf("      ( %1.3f )      ( %1.3f, %1.3f, %1.3f )\n", x(i), P(i,0), P(i,1), P(i,2));
    }
}

void log_given_P_H_R(Matrix<3,3> P, Matrix<1,3> H, Matrix<1,1> R, LOGLEVEL level){
    if (level != DEBUG){ return; }
    printf("   Given:\n");
    printf("   P: ( %1.3f, %1.3f, %1.3f )   H: ( %1.3f, %1.3f, %1.3f )   R: ( %1.3f )\n", P(0,0), P(0,1), P(0,2), H(0,0), H(0,1), H(0,2), R(0));
    for (int i = 1; i < 3; i++)
    {
        printf("      ( %1.3f, %1.3f, %1.3f )\n", P(i,0), P(i,1), P(i,2));
    }
}

void log_result_K(Matrix<3,1> K, LOGLEVEL level){
    if (level != DEBUG){ return; }
    printf("   Result:\n");
    printf("   K: ( %1.3f )\n", K(0));
    for (int i = 1; i < 3; i++)
    {
        printf("      ( %1.3f )\n", K(i));
    }
}

void log_given_x_K_z_P(Matrix<3,1> x, Matrix<3,1> K, Matrix<1,1> z, Matrix<3,3> P, LOGLEVEL level){
    if (level != DEBUG){ return; }
    printf("   Given:\n");
    printf("   x: ( %1.3f )   K: ( %1.3f )   z: ( %1.3f )   P: ( %1.3f, %1.3f, %1.3f )\n", x(0), K(0), z(0), P(0,0), P(0,1), P(0,2));
    for (int i = 1; i < 3; i++)
    {
        printf("      ( %1.3f )      ( %1.3f )                    ( %1.3f, %1.3f, %1.3f )\n", x(i), K(i), P(i,0), P(i,1), P(i,2));
    }

}