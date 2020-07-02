/*
** EPITECH PROJECT, 2019
** my_memset_arr
** File description:
** memset_arr
*/

#include <stdlib.h>

void *my_memset(char *, int, int);

void my_memset_arr(char **arr, int len)
{
    for (int i = 0; i < len; i++) {
        arr[i] = malloc(sizeof(char) * len + 1);
        my_memset(arr[i], 0, len + 1);
    }
}