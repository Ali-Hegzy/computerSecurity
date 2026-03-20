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
            printf("%3d,", mat->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *mat(int rows, int cols, int *data)
{
    Matrix *temp = malloc(sizeof(Matrix));

    if (temp == NULL)
    {
        return NULL;
    }

    temp->rows = rows;
    temp->cols = cols;

    temp->data = malloc(temp->rows * sizeof(int *));

    for (int i = 0; i < temp->rows; i++)
    {
        temp->data[i] = malloc(temp->cols * sizeof(int));
    }

    for (int i = 0; i < temp->rows; i++)
    {
        for (int j = 0; j < temp->cols; j++)
        {
            temp->data[i][j] = data[i * temp->cols + j];
        }
    }

    return temp;
}

void fillMatrix(Matrix *mat, int *data)
{
    for (int i = 0; i < mat->rows; i++)
    {
        for (int j = 0; j < mat->cols; j++)
        {
            mat->data[i][j] = data[i * mat->cols + j];
        }
    }
}

void endMatrix(Matrix *mat)
{
    free(mat);
}
