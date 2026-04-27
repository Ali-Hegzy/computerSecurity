#include "../../../include/ciphers/dec/iciphers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *icaesar(char *cipher, int key)
{
    int len = strlen(cipher);
    char *plain = malloc(len + 1);

    for (int i = 0; i < strlen(cipher); i++)
    {
        plain[i] = (((cipher[i] - 32) - key) % 95) + 32;
    }

    plain[len] = '\0';
    return plain;
}

char *ivigenere(char *cipher, char *keyword)
{
    int len = strlen(cipher);
    int kLen = strlen(keyword);
    char key[len];
    char *plain = malloc(len + 1);

    for (int i = 0; i < len; i++)
    {
        key[i] = keyword[i % kLen] - 32;
    }

    for (int i = 0; i < len; i++)
    {
        int operation = (cipher[i] - 32) - key[i];

        // Modulus arithmetic
        while (operation < 0)
        {
            operation += 95;
        }

        plain[i] = (operation % 95) + 32;
    }

    plain[len] = '\0';
    return plain;
}
