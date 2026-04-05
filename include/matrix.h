#ifndef MATRIX_H
#define MATRIX_H

typedef struct
{
    long rows;
    long cols;
    long *data;
} Matrix;

void printMatrix(Matrix *mat);

Matrix *mat(long rows, long cols, long *data);

void fillMatrix(Matrix *mat, long *data);

void endMatrix(Matrix *mat);

Matrix *matrixMul(Matrix *mat1, Matrix *mat2);

Matrix *scalarModules(Matrix *mat, long num);

#endif