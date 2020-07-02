/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>

void my_memset_arr(char **, int);

int my_strlen(char const *);

char **clean_array(char **, int);

char **my_str_to_word_array_char(char *str, char c)
{
    char **arr = malloc(sizeof(char *) * my_strlen(str));
    int index = 0;
    int j = 0;

    my_memset_arr(arr, my_strlen(str));
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == c || str[i] == '\n') {
            index += 1;
            j = 0;
        } else {
            arr[index][j] = str[i];
            j++;
        }
    }
    return (clean_array(arr, my_strlen(str)));
}