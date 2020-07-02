/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void my_strcpy(char *str1, char *str2)
{
    for (int i = 0; str2[i]; i++)
        str1[i] = str2[i];
}

char *print_key_next(int a, char *ret)
{
    if (a == 38)
        my_strcpy(ret, "Shift");
    if (a == 39)
        my_strcpy(ret, "Alt");
    if (a >= 75 && a <= 84) {
        my_strcpy(ret, "Pad ");
        ret[4] = a - 75 + '0';
    }
    if (a >= 85 && a <= 96) {
        ret[0] = 'F';
        if (a - 85 < 10)
            ret[1] = a - 85 + '0';
        else {
            ret[1] = '1';
            ret[2] = (a - 85) % 10 + '0';
        }
    }
    if (ret[0] == '\0')
        my_strcpy(ret, "Unknown");
    return (ret);
}

char *print_key(int a)
{
    static char *ret = NULL;

    if (!ret)
        ret = malloc(sizeof(char) * 128);
    my_memset(ret, 0, 128);
    if (a >= 0 && a <= 25)
        ret[0] = a + 'A';
    if ((a >= 26 && a <= 35) || a == 51 || a == 56) {
        if (a == 51)
            ret[0] = '4';
        else if (a == 56)
            ret[0] = '6';
        else
            ret[0] = a - 26 + '0';
    }
    if (a == 57)
        my_strcpy(ret, "Space");
    if (a == 37)
        my_strcpy(ret, "Ctrl");
    return (print_key_next(a, ret));
}