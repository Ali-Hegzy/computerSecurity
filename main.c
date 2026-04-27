#include "include/inputs.h"
#include "include/matrix.h"
#include "include/ciphers/enc/ciphers.h"
#include "include/ciphers/dec/iciphers.h"
#include "include/ciphers/enc/utilites.h"
#include "include/controlPanals/encControlPanal.h"
#include "include/controlPanals/decControlPanal.h"
#include "include/controlPanals/mainPanal.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    while (1)
    {
        mainDraw();
        switch (takeChoice())
        {
        case 1:
            encDraw();
            char *cipher = takeCipher();
            printf("%s\n", cipher);
            free(cipher);
            break;

        case 2:
            decDraw();
            char *plain = takeEncrypted();
            printf("%s\n", plain);
            free(plain);
            break;
        }
        printf("==========\n");
    }
}