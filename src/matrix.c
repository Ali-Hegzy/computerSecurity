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
