#include "../../include/ciphers/utilites.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

uint64_t permute(uint64_t input)
{
    int perm_table[] =
        {6, 14, 22, 30, 38, 46, 54, 62, 4, 12, 20, 28, 36, 44, 52, 60,
         2, 10, 18, 26, 34, 42, 50, 58, 0, 8, 16, 24, 32, 40, 48, 56,
         7, 15, 23, 31, 39, 47, 55, 63, 5, 13, 21, 29, 37, 45, 53, 61,
         3, 13, 19, 27, 35, 43, 51, 59, 1, 9, 17, 25, 33, 41, 49, 57};

    uint64_t output = 0;
    for (int i = 0; i < 64; i++)
    {
        uint64_t bit = (input >> perm_table[i]) & 1; // shift to nth bit and then extract it by AND with 1
        output |= (bit << (63 - i));                 // shift the result bit based DES counting and then OR it with the output
    }
    return output;
}

char *strrev(char *text)
{
    int len = strlen(text);
    char *new = malloc(len + 1);
    int j = len - 1;
    for (int i = 0; i < len; i++)
    {
        new[j] = text[i];
        j--;
    }

    new[len] = '\0';

    return new;
}

uint8_t *take64bit(int start, char *text)
{
    uint8_t *part = malloc(9);
    int textStart = start;

    for (int i = 0; i < (start + 8); i++)
    {
        part[i] = text[textStart];
        textStart += 1;
    }

    part[8] = '\0';

    return part;
}