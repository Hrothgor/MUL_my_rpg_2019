/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Return number, sent as a string
*/

#include <stdio.h>
#include <stdlib.h>

int calc_len_int(int nb)
{
    int ret = 0;

    if (nb == 0)
        return (1);
    if (nb < 0) {
        ret += 1;
        nb *= -1;
    }
    while (nb != 0) {
        ret += 1;
        nb /= 10;
    }
    return (ret);
}

char *my_itostr(int nb)
{
    int len = calc_len_int(nb);
    char *ret = malloc(sizeof(char) * len + 1);
    int index = len - 1;

    ret[len] = '\0';
    if (nb < 0) {
        ret[0] = '-';
        nb *= -1;
    }
    if (nb == 0)
        ret[0] = '0';
    while (nb != 0) {
        ret[index] = nb % 10 + 48;
        index -= 1;
        nb /= 10;
    }
    return (ret);
}