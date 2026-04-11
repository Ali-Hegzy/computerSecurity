#ifndef CIPHERS_H
#define CIPHERS_H

#include "../matrix.h"
#include "utilites.h"

char *caesar(char *plain, int key);

char *vigenere(char *plain, char *keyword);

char *hill(char *plain, Matrix *key);

#endif