#include<stdio.h>
#include"../BasicLinearAlgebra-3.6/BasicLinearAlgebra.h"

using namespace BLA;

int main (int argc, char *argv[]){
    BLA::Matrix<2,2> A; // Always <rows, columns>
    A.Fill(0.0);
    A(0,0) = 1.0;
    A(1,1) = 1.0;
    BLA::Matrix<2,2> B;
    B.Fill(0.0);
    B(0,1) = 1.0;
    B(1,0) = 1.0;
    BLA::Matrix<2,2> C = A + B;
    printf("A\n");
    printf("( %f  %f )\n", A(0,0), A(0,1));
    printf("( %f  %f )\n", A(1,0), A(1,1));
    printf("B\n");
    printf("( %f  %f )\n", B(0,0), B(0,1));
    printf("( %f  %f )\n", B(1,0), B(1,1));
    printf("C\n");
    printf("( %f  %f )\n", C(0,0), C(0,1));
    printf("( %f  %f )\n", C(1,0), C(1,1));
}