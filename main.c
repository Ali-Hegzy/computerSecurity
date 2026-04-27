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
    char* result;
    while (1)
    {
        mainDraw();
        switch (takeChoice())
        {
        case 1:
            encDraw();
            result = takeCipher();
            break;

        case 2:
            decDraw();
            result = takeEncrypted();
            break;

        case 3:
            return 0;
        }

        printf("%s\n",result);
        free(result);
        printf("==========\n");
    }
}