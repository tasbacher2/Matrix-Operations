#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main(){

    int i, j, m = -1, n = -1, main;
    struct Matrix m1, transpose;

    printf("Hello Mr. Anderson, welcome to the matrix.\n");

    //build matrix with input from user
    getMatrix(&m1);

    //print matrix
    display(&m1);

    //find the sum of each row
    sumrows(&m1);

    //find the sum of each column
    sumcolumns(&m1);

    //find the sum of the main diagonal of a square matrix
    sumMainDiagonal(&m1);
    

    //transpose matrix
    getTranspose(&m1, &transpose);

    display(&transpose);

    for (int i = 0; i < m1.rows; i++){
        free(m1.matrix[i]);
    } 
    free(m1.matrix);
    
    for (int i = 0; i < m1.rows; i++){
        free(transpose.matrix[i]);
    } 
    free(transpose.matrix);

    return 0;
}

