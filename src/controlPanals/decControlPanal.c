#include "../../include/controlPanals/decControlPanal.h"
#include "../../include/ciphers/dec/iciphers.h"
#include "../../include/inputs.h"
#include <stdio.h>
#include <stdlib.h>
char *decCiphers[] = {"Ceaser"};
int decSize = sizeof(decCiphers) / sizeof(*decCiphers);

void decDraw()
{
    int eleInRow = 2;

    for (int i = 0; i < decSize; i += eleInRow)
    {
        for (int j = 0; j < eleInRow; j++)
        {
            if (i + j < decSize)
            {
                printf("%d-%s\t", (i + j + 1), decCiphers[i + j]);
            }
        }
        printf("\n");
    }
}

char *takeCipherText()
{
    printf("Enter the cipher text\n");
    return input();
}

char *iceaserPanal()
{
    char *cipher = takeCipherText();
    printf("Enter the key\n");

    long key = inputPosNum();

    char *plainText = icaesar(cipher, key);

    free(cipher);
    return plainText;
}

char *takeEncrypted()
{
    while (1)
    {
        long choice = inputPosNum();
        if (choice > decSize)
        {
            printf("undefind choice\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            return iceaserPanal();
        default:
            printf("Not Found\n");
        }
    }
}