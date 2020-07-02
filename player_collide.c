/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

int collide(global_t *g)
{
    int posx = g->player.e.data.pos.x + g->player.e.data.direction.x;
    int posy = g->player.e.data.pos.y + g->player.e.data.direction.y;

    if (g->player.map == 2)
        return (0);
    if (map[(int) ((posy) / 24)][(int) ((posx) / 24)] == 0)
        return (1);
    if (map[(int) ((posy) / 24)][(int) ((posx + 50) / 24)] == 0)
        return (1);
    if (map[(int) ((posy + 50) / 24)][(int) ((posx + 50) / 24)] == 0)
        return (1);
    if (map[(int) ((posy + 50) / 24)][(int) ((posx) / 24)] == 0)
        return (1);
    return (0);
}

int out_of_map(global_t *g)
{
    int posx = g->player.e.data.pos.x + g->player.e.data.direction.x;
    int posy = g->player.e.data.pos.y + g->player.e.data.direction.y;

    if (g->player.map == 2 && posx < 20000)
        return (1);
    if (g->player.map == 2 && posx > 21500)
        return (1);
    if (g->player.map == 2 && posy < 20000)
        return (1);
    if (g->player.map == 2 && posy > 21500)
        return (1);
    if (g->player.map == 1 && posx < 0)
        return (1);
    if (g->player.map == 1 && posx > 9600)
        return (1);
    if (g->player.map == 1 && posy < 0)
        return (1);
    if (g->player.map == 1 && posy > 9600)
        return (1);
    return (0);
}

int collide_boss_map(global_t *g)
{
    int posx = (g->player.e.data.pos.x + g->player.e.data.direction.x) - 20000;
    int posy = (g->player.e.data.pos.y + g->player.e.data.direction.y) - 20000;

    if (g->player.map == 1)
        return (0);
    if (map_boss[(int) ((posy) / 15)][(int) ((posx) / 15)] == 0)
        return (1);
    if (map_boss[(int) ((posy) / 15)][(int) ((posx + 50) / 15)] == 0)
        return (1);
    if (map_boss[(int) ((posy + 50) / 15)][(int) ((posx + 50) / 15)] == 0)
        return (1);
    if (map_boss[(int) ((posy + 50) / 15)][(int) ((posx) / 15)] == 0)
        return (1);
    return (0);
}