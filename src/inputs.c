#include "../include/inputs.h"
#include "../include/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

char *input()
{
    int size = 10;
    char *text = malloc(size);

    if (text == NULL)
        return NULL;

    int i = 0;
    int x;
    while (1)
    {
        x = getchar();
        if (x == '\n' || x == EOF)
            break;

        text[i] = (char)x;
        i++;
        if (i == size - 1)
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
    text[i] = '\0';

    return text;
}

long inputPosNum()
{
    long new;
    while (1)
    {
        char *str = input();
        char *end;

        errno = 0;
        new = strtol(str, &end, 10);

        if (errno == ERANGE)
        {
            printf("Large number detected, Enter a smaller number\n");
            free(str);
            continue;
        }

        if (*end != '\0' || new < 0 || str == end)
        {
            printf("Enter a valid positive number\n");
            free(str);
            continue;
        }

        free(str);
        return new;
    }
}

long inputNum()
{
    long new;
    while (1)
    {
        char *str = input();
        char *end;

        errno = 0;
        new = strtol(str, &end, 10);

        if (errno == ERANGE)
        {
            printf("Large number detected, Enter a smaller number\n");
            free(str);
            continue;
        }

        if (str == end || (*end != '\0' && *end != '\n'))
        {
            printf("Enter a valid number\n");
            free(str);
            continue;
        }

        free(str);
        return new;
    }
}

Matrix *inputMatrix()
{
    printf("Enter the number of rows\n");
    long rows = inputNum();

    printf("Enter the number of columns\n");
    long cols = inputNum();

    long *nums = malloc(rows * cols * sizeof(long));

    for (long i = 0; i < rows; i++)
    {
        for (long j = 0; j < cols; j++)
        {
            printf("Enter the element in row number %ld and column number %ld\n", i + 1, j + 1);
            nums[i * cols + j] = inputNum();
        }
    }

    Matrix *temp = mat(rows, cols, nums);

    return temp;
}