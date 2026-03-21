#include "include/matrix.h"
#include "include/ciphers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int num[] = {2, 4, 5, 9, 2, 1, 3, 17, 7};
    Matrix *key = mat(3, 3, num);

    char *cipher = hill("attackatdawn", key);

    printf("%s\n", cipher);

    free(cipher);
    return 0;
}