/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

int inwall_ennemi(global_t *g, int i)
{
    int posx = g->ennemi[i].e.data.pos.x;
    int posy = g->ennemi[i].e.data.pos.y;

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

void ennemi_death(global_t *g, int i)
{
    if (g->ennemi[i].e.hp <= 0) {
        drop_items(g->ennemi[i], g);
        g->ennemi[i].e.data.init = 0;
        sfClock_restart(g->ennemi[i].respawn);
    }
}

void respawn_ennemi(global_t *g, int i)
{
    sfTime time;

    time = sfClock_getElapsedTime(g->ennemi[i].respawn);
    g->ennemi[i].respawn_second = time.microseconds / 1000000.0;
    if (g->ennemi[i].respawn_second > 10) {
        g->ennemi[i].e.hp = g->ennemi[i].e.maxhp;
        g->ennemi[i].e.data.init = 1;
        g->ennemi[i].e.data.pos.x = (rand() % (g->ennemi[i].zone.width - \
        g->ennemi[i].zone.left + 1)) + g->ennemi[i].zone.left;
        g->ennemi[i].e.data.pos.y = (rand() % (g->ennemi[i].zone.height - \
        g->ennemi[i].zone.top + 1)) + g->ennemi[i].zone.top;
        while (inwall_ennemi(g, i)) {
            g->ennemi[i].e.data.pos.x = (rand() % (g->ennemi[i].zone.width - \
            g->ennemi[i].zone.left + 1)) + g->ennemi[i].zone.left;
            g->ennemi[i].e.data.pos.y = (rand() % (g->ennemi[i].zone.height - \
            g->ennemi[i].zone.top + 1)) + g->ennemi[i].zone.top;
        }
        sfClock_restart(g->ennemi[i].respawn);
    }
}