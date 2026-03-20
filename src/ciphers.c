#include "../include/ciphers.h"
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
