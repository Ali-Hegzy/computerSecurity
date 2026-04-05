#include "../include/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printMatrix(Matrix *mat)
{
    if (mat == NULL) return;

    for (long i = 0; i < mat->rows; i++)
    {
        for (long j = 0; j < mat->cols; j++)
        {
            printf("%3ld,", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

Matrix *mat(long rows, long cols, long *data)
{
    Matrix *temp = malloc(sizeof(Matrix));

    if (temp == NULL)
        return NULL;

    temp->rows = rows;
    temp->cols = cols;

    temp->data = malloc(temp->rows * temp->cols * sizeof(long));

    if (temp->data == NULL)
    {
        free(temp);
        return NULL;
    }

    temp->data = data;

    return temp;
}

void fillMatrix(Matrix *mat, long *data)
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

    long *num = malloc(mat1->rows * mat2->cols * sizeof(long));

    if (num == NULL)
        return NULL;

    long accum = 0;

    for (long i = 0; i < mat1->rows; i++)
    {
        for (long j = 0; j < mat2->cols; j++)
        {
            accum = 0;
            for (long k = 0; k < mat1->cols; k++)
            {
                accum += (mat1->data[i * mat1->cols + k]) * (mat2->data[k * mat2->cols + j]);
            }
            num[i * mat2->cols + j] = accum;
        }
    }

    Matrix *answer = mat(mat1->rows, mat2->cols, num);
    return answer;
}

Matrix *scalarModules(Matrix *mat,long num)
{
    for(long i=0;i< mat->rows;i++)
    {
        for (long j = 0;j < mat->cols; j++)
        {
            mat->data[i * mat->cols + j] %= num;
        }
    }

    return mat;
}