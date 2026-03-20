#include "../include/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printMatrix(Matrix *mat)
{
    for (int i = 0; i < mat->rows; i++)
    {
        for (int j = 0; j < mat->cols; j++)
        {
            printf("%3d,", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

Matrix *mat(int rows, int cols, int *data)
{
    Matrix *temp = malloc(sizeof(Matrix));

    if (temp == NULL)
        return NULL;

    temp->rows = rows;
    temp->cols = cols;

    temp->data = malloc(temp->rows * temp->cols * sizeof(int));

    if (temp->data == NULL)
    {
        free(temp);
        return NULL;
    }

    temp->data = data;

    return temp;
}

void fillMatrix(Matrix *mat, int *data)
{
    mat->data = data;
}

void endMatrix(Matrix *mat)
{
    free(mat);
}

Matrix *matrixMul(Matrix *mat1, Matrix *mat2)
{
    if (mat1->cols != mat2->rows)
    {
        printf("Columns of first matrix does not equal the Rows of Second matrix.\n");
        return NULL;
    }

    int *num = malloc(mat1->rows * mat2->cols * sizeof(int));

    if (num == NULL)
        return NULL;

    int accum = 0;

    for (int i = 0; i < mat1->rows; i++)
    {
        for (int j = 0; j < mat2->cols; j++)
        {
            accum = 0;
            for (int k = 0; k < mat1->cols; k++)
            {
                accum += (mat1->data[i * mat1->cols + k]) * (mat2->data[k * mat2->cols + j]);
            }
            num[i * mat2->cols + j] = accum;
        }
    }

    Matrix *answer = mat(mat1->rows, mat2->cols, num);
    return answer;
}
