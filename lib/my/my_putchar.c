/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char c, int fd)
{
    write(fd, &c, 1);
}
