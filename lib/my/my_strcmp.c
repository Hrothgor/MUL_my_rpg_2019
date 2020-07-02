/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** my_strcmp
*/

#include <string.h>

int my_strlen(char const *);

void my_putchar(char);

int my_strcmp(char const *s1, char const *s2)
{
    int longueur = my_strlen(s1);

    for (int i = 0; i < longueur; i++)
        if (s1[i] != s2[i])
            return (0);
    return (1);
}
