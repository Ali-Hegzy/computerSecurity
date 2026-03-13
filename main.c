#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int **matrixMul(int (*mat1)[3], int (*mat2)[1])
{
    int rows = 3;
    int cols = 1;

    int **sum = malloc(rows * sizeof(int *));

    for (int i = 0; i < 3; i++)
    {
        sum[i] = malloc(cols * sizeof(int));
    }

    for (int k = 0; k < rows; k++)
    {
        for (int l = 0; l < cols; l++)
        {
            int accum = 0;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 1; j++)
                {
                    accum += (mat1[j][i]) * (mat2[i][j]);
                }
            }

            sum[k][l] = accum;
        }
    }

    return sum;
}

int main()
{
    int arr1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    int arr2[3][1] = {
        {2},
        {5},
        {7}};

    int **sum;
    sum = matrixMul(arr1, arr2);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            printf("%d,", sum[i][j]);
        }
        printf("\n");
    }
}