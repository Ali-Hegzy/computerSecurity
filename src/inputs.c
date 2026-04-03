#include "../include/inputs.h"
#include <stdio.h>
#include <stdlib.h>

char *input()
{
    int size = 10;
    char *text = malloc(10 * 1);

    if (text == NULL)
        return NULL;

    int i = 0;
    char x;
    while (1)
    {
        x = getchar();
        if (x == '\n')
            break;

        text[i] = x;
        i++;
        if (i == size)
        {
            char *tmp = realloc(text, size + 10);
            if (tmp != NULL)
            {
                text = tmp;
                size += 10;
            }
            else
            {
                return NULL;
            }
        }
    }

    return text;
}