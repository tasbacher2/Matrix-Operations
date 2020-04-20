#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

/* 

Matrix Operations

Description:

TODO:
better input validation for matrix data

*/

void getMatrix(struct Matrix *m)
{
    int valid = 0;

    m->rows = 0;
    m->cols = 0;
    m->active = 1;

    //get dimensions from user
    //triggers infinite loop if string entered
    printf("Please enter the number of rows (max 20): ");
    while (m->rows < 1 || m->rows > 20){
        valid = scanf("%d", &m->rows);
        if (m->rows < 1 || m->rows > 20 || valid == 0){
            printf("Incorrect input, please enter the number of rows (max 20): ");
            fflush(stdin);
        }
    }
    printf("Please enter the number of columns (max 20): ");
    while (m->cols < 1 || m->cols > 20){
        scanf("%d", &m->cols);
        if (m->cols < 1 || m->cols > 20 || valid == 0){
            printf("Incorrect input, please enter the number of rows (max 20): ");
            fflush(stdin);
        }
    }

    // Allocate memory for matrix
    m->matrix = malloc(m->rows*sizeof(float*));
    for (int i = 0; i < m->rows; i++){
        m->matrix[i] = malloc(m->cols*sizeof(float));
    } 

    // Build matrix with input from user
    valid = 0;
    for (int i=0; i<m->rows; i++){
        for (int j=0; j<m->cols; j++){
            valid = 0;
            printf("Enter value for cell %d, %d: ", i, j);
            while (m->matrix[i][j] > FLT_MAX || valid == 0){
                valid = scanf("%f", &m->matrix[i][j]);
                printf("");
                if (m->matrix[i][j] > FLT_MAX || valid == 0){
                    printf("Incorrect input, please enter a number: ");
                    fflush(stdin);
                }
            }
        }
    }
}

void freeMatrix(struct Matrix *m){
    for (int i = 0; i < m->rows; i++){
        free(m->matrix[i]);
    } 
    free(m->matrix);
}


void display(struct Matrix *m){
    for (int i=0; i<m->rows; i++){
        for (int j=0; j<m->cols; j++){
            printf("%.1f\t", m->matrix[i][j]);
        }
        printf("\n");
    }
    fflush(stdin);
}

void sumrows(struct Matrix *m){
    float sum;
    for (int i=0; i<m->rows; i++){
        sum = 0;
        for (int j=0; j<m->cols; j++){
            sum += m->matrix[i][j];
        }
        printf("The sum of the values in row %d is: %d\n", i + 1, sum);
    }
}

void sumcolumns(struct Matrix *m){
    float sum;
    for (int i=0; i<m->cols; i++){
        sum = 0;
        for (int j=0; j<m->rows; j++){
            sum += m->matrix[j][i];
        }
        printf("The sum of the values in column %d is: %d\n", i + 1, sum);
    }
}

void sumMainDiagonal(struct Matrix *m){
    int sum = 0;
    if (m->rows != m->cols){
        printf("This function requires a square matrix.\n");
    }
    else{
        for (int i=0; i<m->rows; i++){
            sum += m->matrix[i][i];
        }
        printf("The sum of the main diagonal of this matrix is: %d\n", sum);
    }
}

void getTranspose(struct Matrix *m1, struct Matrix *m2){
    m2->rows = m1->cols;
    m2->cols = m1->rows;
    m2->active = 1;

    m2->matrix = malloc(m2->rows*sizeof(int*));
    for (int i = 0; i < m2->rows; i++){
        m2->matrix[i] = malloc(m2->cols*sizeof(int));
    } 

    for (int i=0; i<m1->rows; i++){
        for (int j=0; j<m1->cols; j++){
            m2->matrix[j][i] = m1->matrix[i][j];
        }
    }
}

void getSum(struct Matrix *m1, struct Matrix *m2, struct Matrix *m3){

    if (m1->rows == m2->rows && m1->cols == m2->cols){
        m3->rows = m1->rows;
        m3->cols = m1->cols;
        m3->active = 1;

        m3->matrix = malloc(m3->rows*sizeof(int*));
        for (int i = 0; i < m3->rows; i++){
            m3->matrix[i] = malloc(m3->cols*sizeof(int));
        } 

        for (int i=0; i<m3->rows; i++){
            for (int j=0; j<m3->cols; j++){
                m3->matrix[i][j] = m1->matrix[i][j] + m2->matrix[i][j];
            }
        }
    }
    else{
        printf("Error, Matrix dimensions must match for addition.\n");
        printf("Please try again with two matricies that are the same size.\n");
    }
}

void getDifference(struct Matrix *m1, struct Matrix *m2, struct Matrix *m3){

    if (m1->rows == m2->rows && m1->cols == m2->cols){
        m3->rows = m1->rows;
        m3->cols = m1->cols;
        m3->active = 1;

        m3->matrix = malloc(m3->rows*sizeof(int*));
        for (int i = 0; i < m3->rows; i++){
            m3->matrix[i] = malloc(m3->cols*sizeof(int));
        } 

        for (int i=0; i<m3->rows; i++){
            for (int j=0; j<m3->cols; j++){
                m3->matrix[i][j] = m1->matrix[i][j] - m2->matrix[i][j];
            }
        }
    }
    else{
        printf("Error, Matrix dimensions must match for for subtraction.\n");
        printf("Please try again with two matricies that are the same size.\n");
    }
}

void getProduct(struct Matrix *m1, struct Matrix *m2, struct Matrix *m3){
    float sum;

    if (m1->cols == m2->rows){
        m3->rows = m1->rows;
        m3->cols = m2->cols;
        m3->active = 1;

        m3->matrix = malloc(m3->rows*sizeof(float*));
        for (int i = 0; i < m3->rows; i++){
            m3->matrix[i] = malloc(m3->cols*sizeof(float));
        } 

        for (int i=0; i<m3->rows; i++){
            for (int j=0; j<m3->cols; j++){
                sum = 0;
                for (int o=0; o<m1->cols; o++){
                    sum += m1->matrix[i][o] * m2->matrix[o][j];
                }
                m3->matrix[i][j] = sum;
            }
        }
    }
    else{
        printf("Error, Amount of columns of the first matrix must equal the amount of rows in the second matrix.\n");
        printf("Please try again with correct dimensions for multiplication.\n");
    }
}

float det(float m[20][20], int n){
    float minor[20][20], sign = 1, determinant = 0;

    if (n == 1){
        determinant = m[0][0];
    }
    else if (n == 2){
        determinant = m[0][0] * m[1][1] - m[0][1] * m[1][0];
    }
    else{
        //TODO
        for (int k = 0; k < n; k++){
            //This loop tracks a11 to a1k
            for (int i = 1; i < n; i++){
                //tracks rows, keep all except for row 1
                for (int j = 0; j < k; j++){
                    //all of the columns before k
                    minor[i - 1][j] = m[i][j];
                }
                for (int j = k + 1; j < n; j++){
                    //all of the columns after k
                    minor[i - 1][j-1] = m[i][j];
                }
            }
            determinant += sign * m[0][k] * det(minor, n - 1);
            sign *= -1;
        }
    }
    return determinant;
}

void getInverse(float matrix[20][20], struct Matrix *m2, int n){
    // is the dimension of the square matrix
    float minor[20][20], cofactor[20][20];
    float determinant = 0, sign = 1, minorDet = 0;

    m2->rows = n;
    m2->cols = n;
    m2->active = 1;

    m2->matrix = malloc(m2->rows*sizeof(float*));
    for (int i = 0; i < m2->rows; i++){
        m2->matrix[i] = malloc(m2->cols*sizeof(float));
    } 

    if (n == 1){
        // 1x1 matrix inverse is the recipricol of the element
        printf("here %f\n", 1 / matrix[0][0]);
        m2->matrix[0][0] = 1 / matrix[0][0];
    }
    else if (n == 2){
        // 2x2 Matrix inverse
        determinant = det(matrix, n);
        m2->matrix[0][0] = (1 / determinant) * matrix[1][1];
        m2->matrix[0][1] = -1 * (1 / determinant) * matrix[0][1];
        m2->matrix[1][0] = -1 * (1 / determinant) * matrix[1][0];
        m2->matrix[1][1] = (1 / determinant) * matrix[0][0];
    }
    else{
        determinant = det(matrix, n);
        //TODO NxN
        //create the matrix of cofactors
        for (int l = 0; l < n; l++){
            //current row
            for (int k = 0; k < n; k++){
                //current column
                
                //for each element [l][k]
                //create the minor
                for (int i = 0; i < l; i++){
                    // all the rows before the current row
                    for (int j = 0; j < k; j++){
                        // all of the columns before current column
                        minor[i][j] = matrix[i][j];
                    }
                    for (int j = k + 1; j < n; j++){
                        //all of the columns after current column
                        minor[i][j-1] = matrix[i][j];
                    }
                }
                for (int i = l + 1; i < n; i++){
                    // all the rows after the current row
                    for (int j = 0; j < k; j++){
                        // all of the columns before current column
                        minor[i-1][j] = matrix[i][j];
                    }
                    for (int j = k + 1; j < n; j++){
                        //all of the columns after current column
                        minor[i-1][j-1] = matrix[i][j];
                    }
                }
                minorDet = det(minor, n-1);
                if (minorDet == 0){
                    // avoids negative 0
                    cofactor[l][k] = 0;
                }
                else{
                    cofactor[l][k] = sign * det(minor, n-1);
                }
                sign *= -1;
            }
        }
        // Transpose the matrix of cofactors and multiply by the recipricol of determinant
        for (int i=0; i < n; i++){
            for (int j=0; j < n; j++){
                m2->matrix[j][i] = (1 / determinant) * cofactor[i][j];
            }
        }
        
        //invert negatives for odd columns
        if (!(n % 2)){
            for (int j=1; j < n; j++){
                for (int i = 0; i < n; i++){
                    if (j%2){
                        m2->matrix[i][j] *= -1;
                        //gets rid of -0.0 for some reason there's a negative 0???
                        if (m2->matrix[i][j] == 0){
                            m2->matrix[i][j] += 1;
                            m2->matrix[i][j] -= 1;
                        }
                    }
                }
            }
        }

    }
    
}