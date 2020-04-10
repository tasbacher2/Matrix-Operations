#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int **matrix;
    int rows, cols;
};

void getMatrix(struct Matrix *m)
{
    int valid = 0;

    m->rows = 0;
    m->cols = 0;

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
    m->matrix = malloc(m->rows*sizeof(int*));
    for (int i = 0; i < m->rows; i++){
        m->matrix[i] = malloc(m->cols*sizeof(int));
    } 

    // Build matrix with input from user
    valid = 0;
    for (int i=0; i<m->rows; i++){
        for (int j=0; j<m->cols; j++){
            valid = 0;
            printf("Enter value for cell %d, %d: ", i, j);
            while (valid == 0){
                valid = scanf("%d", &m->matrix[i][j]);
                if (valid == 0){
                    printf("Incorrect input, please enter a number: ");
                    fflush(stdin);
                }
            }
        }
    }
}

void display(struct Matrix *m){
    for (int i=0; i<m->rows; i++){
        for (int j=0; j<m->cols; j++){
            printf("%d\t", m->matrix[i][j]);
        }
        printf("\n");
    }
}

void sumrows(struct Matrix *m){
    int sum;
    for (int i=0; i<m->rows; i++){
        sum = 0;
        for (int j=0; j<m->cols; j++){
            sum += m->matrix[i][j];
        }
        printf("The sum of the values in row %d is: %d\n", i + 1, sum);
    }
}

void sumcolumns(struct Matrix *m){
    int sum;
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
            for (int j=0; j<m->cols; j++){
                if (i == j){
                    sum += m->matrix[i][j];
                }
            }
        }
        printf("The sum of the main diagonal of this matrix is: %d\n", sum);
    }
}

void getTranspose(struct Matrix *m1, struct Matrix *m2){
    m2->rows = m1->cols;
    m2->cols = m1->rows;

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

