/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *);

void my_memset(char *, int, int);

char *my_strdup(char const *src)
{
    char *ret;

    ret = malloc(sizeof(char) * my_strlen(src) + 1);
    my_memset(ret, 0, my_strlen(src) + 1);
    for (int i = 0; src[i] != '\0'; i++)
        ret[i] = src[i];
    return (ret);
}
