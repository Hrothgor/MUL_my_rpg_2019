/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** my_strcat
*/

#include <stdlib.h>

int my_strlen(char const *);

void my_memset(char *, int, int);

char *my_strcat(char *dest, char const *src)
{
    char *ret = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    int index = 0;

    my_memset(ret, 0, my_strlen(dest) + my_strlen(src) + 1);
    for (int i = 0; i < my_strlen(dest); i++) {
        ret[index] = dest[i];
        index += 1;
    }
    for (int i = 0; i < my_strlen(src); i++) {
        ret[index] = src[i];
        index += 1;
    }
    ret[index] = '\0';
    return (ret);
}
