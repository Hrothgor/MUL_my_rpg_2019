/*
** EPITECH PROJECT, 2019
** my_strncmp.c
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
        i++;
    if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
        return (1);
    else if (s1[i] > s2[i])
        return (0);
    else
        return (0);
}
