#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *caesarCipher(char *plain, int key)
{
    int len = strlen(plain);
    char *cipher = malloc(len + 1);

    for (int i = 0; i < strlen(plain); i++)
    {
        cipher[i] = ((plain[i] + key) % 26);
    }

    cipher[len] = '\0';
    return cipher;
}

int main()
{
    char plain[] = "Hello World";
    char *cipher = caesarCipher(plain, 3);

    printf("%s\n", plain);
    printf("%p\n", plain);

    free(cipher);
}