#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *caesarCipher(char *plain, int key)
{
    int len = strlen(plain);
    char *cipher = malloc(len + 1);

    for (int i = 0; i < strlen(plain); i++)
    {
        if (islower(plain[i]))
        {
            cipher[i] = (((plain[i] - 'a') + key) % 26) + 'a';
        }
        else if (isupper(plain[i]))
        {
            cipher[i] = (((plain[i] - 'A') + key) % 26) + 'A';
        }
        else
        {
            cipher[i] = plain[i];
        }
    }

    cipher[len] = '\0';
    return cipher;
}

int main()
{
    char plain[50];
    int key;

    printf("Enter the plain text [it's size is 50 character]:\n");
    fgets(plain, sizeof(plain), stdin);
    printf("Enter the key:\n");
    scanf("%d", &key);

    char *cipher = caesarCipher(plain, key);

    printf("Plain text: %s", plain);
    printf("Cipher text: %s", cipher);
    printf("Key: %d\n", key);

    free(cipher);
}