/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void print_new_save2(global_t *g, int fd)
{
    for (int i = 0; i < 34; i++) {
        if (g->player.inventory[i].item.init) {
            my_putstr(my_itostr(g->player.inventory[i].ID), fd);
        } else {
            my_putstr("0", fd);
        }
        if (i < 33)
            my_putstr(",", fd);
    }
    my_putstr("\n", fd);
    my_putstr(my_itostr(g->player.e.data.pos.x), fd);
    my_putstr("\n", fd);
    my_putstr(my_itostr(g->player.e.data.pos.y), fd);
    my_putstr("\n", fd);
    my_putstr(my_itostr(g->player.nb_quest), fd);
    my_putstr("\n", fd);
    my_putstr(my_itostr(g->player.end), fd);
    my_putstr("\n", fd);
}

void print_new_save(global_t *g)
{
    int fd = open(my_strcat("save/", g->player.e.name), \
    O_CREAT | O_WRONLY | O_TRUNC, 0666);

    my_putstr(my_itostr(g->player.e.level), fd);
    my_putstr("\n", fd);
    my_putstr(my_itostr(g->player.gold), fd);
    my_putstr("\n", fd);
    my_putstr(my_itostr(g->player.race), fd);
    my_putstr("\n", fd);
    print_new_save2(g, fd);
    close(fd);
}