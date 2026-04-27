#include "../../include/controlPanals/mainPanal.h"
#include "../../include/inputs.h"
#include <stdio.h>
char *options[] = {"Encryption", "Decryption", "Close"};
int mainSize = sizeof(options) / sizeof(*options);

void mainDraw()
{
    int eleInRow = 3;

    for (int i = 0; i < mainSize; i += eleInRow)
    {
        for (int j = 0; j < eleInRow; j++)
        {
            if (i + j < mainSize)
            {
                printf("%d-%s\t", (i + j + 1), options[i + j]);
            }
        }
        printf("\n");
    }
}

int takeChoice()
{
    while (1)
    {
        long choice = inputPosNum();
        if (choice > mainSize)
        {
            printf("undefind choice\n");
            continue;
        }

        return choice;
    }
}