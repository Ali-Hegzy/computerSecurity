#include "../../include/controlPanals/encControlPanal.h"
#include "../../include/ciphers/enc/ciphers.h"
#include "../../include/inputs.h"
#include <stdio.h>
#include <stdlib.h>
char *ciphers[] = {"Ceaser", "Vigener", "Hill"};
int size = sizeof(ciphers) / sizeof(*ciphers);

void encDraw()
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

char *takePlain()
{
    printf("Enter the plain text\n");
    return input();
}

char *ceaserPanal()
{
    char *plain = takePlain();
    printf("Enter the key\n");

    long key = inputPosNum();

    char *cipherText = caesar(plain, key);

    free(plain);
    return cipherText;
}

char *vigenerePanal()
{
    char *plain = takePlain();
    printf("Enter the keyword\n");

    char *keyword = input();

    char *cipherText = vigenere(plain, keyword);

    free(plain);
    free(keyword);
    return cipherText;
}

char *hillPanal()
{
    char *plain = takePlain();
    printf("Enter the keyword\n");

    Matrix *keyword = inputMatrix(1);

    char *cipherText = hill(plain, keyword);

    free(plain);
    endMatrix(keyword);
    return cipherText;
}

/**
 * @brief
 * حقل ادخال عام يقوم باخذ رقم الاختيار من المستخدم و التحقق من صحته و يوجه للشفرة المطلوبة
 * @return
 * النص المشفر
 */
/**
 * @brief
 * General input gate that take the number of cipher the user need and check it them route the user to the needed cipher.
 * @return
 * The encrypted cipher.
 */
char *takeCipher()
{
    while (1)
    {
        long choice = inputPosNum();
        if (choice > size)
        {
            printf("undefind choice\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            return ceaserPanal();
        case 2:
            return vigenerePanal();
        case 3:
            return hillPanal();
        default:
            printf("Not Found\n");
        }
    }
}