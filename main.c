#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct matrix
{
    int rows;
    int cols;
    int data[3][3];
};

char *caesar(char *plain, int key)
{
    int len = strlen(plain);
    char *cipher = malloc(len + 1);

    for (int i = 0; i < strlen(plain); i++)
    {
        if (islower(plain[i]))
        {
            cipher[i] = (((plain[i] - 'a') + key) % 26) + 'a';
        }
        else if (isupper(plain[i]))
        {
            cipher[i] = (((plain[i] - 'A') + key) % 26) + 'A';
        }
        else
        {
            cipher[i] = plain[i];
        }
    }

    cipher[len] = '\0';
    return cipher;
}

char *playfair(char *plain, char *keyword)
{
    int len = strlen(plain);
    char *cipher = malloc(len + 1);

    cipher[len] = '\0';
    return cipher;
}

char *vigenere(char *plain, char *keyword)
{
    int len = strlen(plain);
    int kLen = strlen(keyword);
    char key[len];
    char *cipher = malloc(len + 1);

    for (int i = 0; i < len; i++)
    {
        key[i] = keyword[i % kLen] - 'a';
    }

    for (int i = 0; i < len; i++)
    {
        if (islower(plain[i]))
        {
            cipher[i] = ((key[i] + (plain[i] - 'a')) % 26) + 'a';
        }
        else if (isupper(plain[i]))
        {
            cipher[i] = ((key[i] + (plain[i] - 'A')) % 26) + 'A';
        }
        else
        {
            cipher[i] = plain[i];
        }
    }

    cipher[len] = '\0';
    return cipher;
}

char *hill()
{
}

struct matrix matrixMul(struct matrix mat1, struct matrix mat2)
{
    int mat1Rows = mat1.rows;
    int mat2Cols = mat2.cols;

    int rows = mat1Rows;
    int cols = mat2Cols;
    struct matrix answer = {rows,cols};

    int accum = 0;

    for (int k = 0; k < cols; k++)
    {
        for (int z = 0; z < rows; z++)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    accum += (mat1.data[j + z][i]) * (mat2.data[i][j]);
                }
            }
            answer.data[z][k] = accum;
            accum = 0;
        }
    }

    return answer;
}

int main()
{
    struct matrix arr1 = {3, 3, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    struct matrix arr2 = {3, 1, {{2},{5},{7}}};

    struct matrix sum = matrixMul(arr1, arr2);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d,", sum.data[i][j]);
        }
        printf("\n");
    }
}