#include "../include/controlPanal.h"
#include <stdio.h>

void draw(){
    char *ciphers[] = {"Ceaser", "Hill", "Vigener", "DES", "AES"};
    int size = sizeof(ciphers) / sizeof(*ciphers);
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