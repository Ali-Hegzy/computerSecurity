#include "../include/controlPanal.h"
#include "../include/ciphers.h"
#include "../include/inputs.h"
#include <stdio.h>
char *ciphers[] = {"Ceaser", "Hill", "Vigener", "DES", "AES"};
int size = sizeof(ciphers) / sizeof(*ciphers);

void draw()
{
    int eleInRow = 2;

    for (int i = 0; i < size; i += eleInRow)
    {
        for (int j = 0; j < eleInRow; j++)
        {
            if (i + j < size)
            {
                printf("%d-%s\t", (i + j + 1), ciphers[i + j]);
            }
        }
        printf("\n");
    }
}

char* ceaserPanal()
{
    printf("Enter the plain text\n");
    char* plain = input();
    printf("Enter the key\n");
    long key = inputPosNum();
    return caesar(plain,key);
}