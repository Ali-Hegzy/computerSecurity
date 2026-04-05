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

char *takePlain()
{
    printf("Enter the plain text\n");
    char *plain = input();
}

char *ceaserPanal()
{
    char *plain = takePlain();
    printf("Enter the key\n");
    long key = inputPosNum();
    return caesar(plain, key);
}

char *vigenerePanal()
{
    char *plain = takePlain();
    printf("Enter the keyword\n");
    char *keyword = input();
    return vigenere(plain, keyword);
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
        if (choice >= size)
        {
            printf("undefind choice\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            return ceaserPanal();
        case 3:
            return vigenerePanal();
        default:
            printf("Not Found\n");
        }
    }
}