struct Matrix
{
    int **matrix;
    int rows, cols;
};

void getMatrix(struct Matrix *m);
void freeMatrix(struct Matrix *m);
void display(struct Matrix *m);
void sumrows(struct Matrix *m);
void sumcolumns(struct Matrix *m);
void sumMainDiagonal(struct Matrix *m);
void getTranspose(struct Matrix *m1, struct Matrix *m2);
void getSum(struct Matrix *m1, struct Matrix *m2, struct Matrix *m3);
void getDifference(struct Matrix *m1, struct Matrix *m2, struct Matrix *m3);
void getProduct(struct Matrix *m1, struct Matrix *m2, struct Matrix *m3);