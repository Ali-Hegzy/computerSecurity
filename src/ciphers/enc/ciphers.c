#include "../../../include/matrix.h"
#include "../../../include/ciphers/enc/utilites.h"
#include "../../../include/ciphers/enc/ciphers.h"
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
        cipher[i] = (((plain[i] - 32) + key) % 95) + 32;
    }

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
        key[i] = keyword[i % kLen] - 32;
    }

    for (int i = 0; i < len; i++)
    {
        cipher[i] = (((plain[i] - 32) + key[i]) % 95) + 32;
    }

    cipher[len] = '\0';
    return cipher;
}

char *hill(char *plain, Matrix *key)
{
    int len = strlen(plain);
    char *cipher;
    int diff = len % (key->rows);
    if (diff != 0)
    {
        char *temp = malloc((len + diff) * sizeof(char));
        for (int i = 0; i < len; i++)
        {
            temp[i] = plain[i];
        }
        for (int i = len; i < (len + diff); i++)
        {
            temp[i] = 'x';
        }
        len = strlen(temp);
        plain = temp;
    }

    cipher = malloc(len + 1);

    for (int i = 0; i < len; i += (key->rows) /*or (key->cols)*/)
    {
        long *num = malloc(key->rows * sizeof(long));
        Matrix *temp = mat(key->rows, 1, num);

        for (int j = 0; j < key->rows; j++)
        {
            num[j] = plain[i + j] - 32;
        }

        Matrix *matOfNums = scalarModules(matrixMul(key, temp), 95);

        for (int k = 0; k < key->rows; k++)
        {
            cipher[i + k] = matOfNums->data[k] + 32;
        }

        endMatrix(temp);
        endMatrix(matOfNums);
    }

    cipher[len] = '\0';
    return cipher;
}