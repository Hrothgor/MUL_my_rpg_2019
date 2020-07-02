/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** my_putstr
*/

#include <unistd.h>

void my_putchar(char, int);

void my_putstr(char const *str, int fd)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i], fd);
}
