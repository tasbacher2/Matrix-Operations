#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

/* 

Matrix Operations

Description:

TODO:
create an Array (10 max?) for maximum amount of M pointers
Add an 'active' flag to the matrix struct
create an interactive menu
implement more operations

*/

int main(){

    int i, j, m = -1, n = -1, main;
    struct Matrix m1, /*transpose,*/ m2, m3;

    printf("Hello Mr. Anderson, welcome to the matrix.\n");

    //build matrix with input from user
    getMatrix(&m1);
    getMatrix(&m2);

    //print matrix
    //display(&m1);

    //find the sum of each row
    //sumrows(&m1);

    //find the sum of each column
    //sumcolumns(&m1);

    //find the sum of the main diagonal of a square matrix
    //sumMainDiagonal(&m1);

    //transpose matrix
    //getTranspose(&m1, &transpose);

    //display(&transpose);

    //getSum(&m1, &m2, &m3);
    //getDifference(&m1, &m2, &m3);
    //display(&m3);

    freeMatrix(&m1);
    freeMatrix(&m2);
    //freeMatrix(&m3);
    //freeMatrix(&transpose);

    return 0;
}

