#ifndef CIPHERS_H
#define CIPHERS_H

char *caesar(char *plain, int key);

char *vigenere(char *plain, char *keyword);

char *hill(char *plain, Matrix *key);

#endif