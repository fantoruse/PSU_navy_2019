/*
** EPITECH PROJECT, 2020
** tkt
** File description:
** tkt
*/

#include <stdlib.h>
#include <stdio.h>
#include "navy.h"
#include "my.h"

static const char let[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

int *transform_input(char *input, int *result)
{
    int i = 0;

    if (input[0] >= 'A' && input[0] <= 'H') {
        for (; let[i] != input[0]; i++);
        result[0] = (i+1);
        result[1] = input[1] - '0';
    } else {
        for (; let[i] != input[1]; i++);
        result[0] = (i+1);
        result[1] = input[0] - '0';
    }
    return (result);
}

int cat_input(char **input)
{
    *input = NULL;
    size_t getnext = 0;

    my_putstr("\nattack: ");
    if (getline(input, &getnext, stdin) == -1)
        return  -1;
    return 0;
}
