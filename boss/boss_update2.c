/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void update_boss_phase2(global_t *g, int i, int j)
{
    g->ennemi[j].e.maxmana = g->ennemi[j].e.mana;
    g->ennemi[j].e.maxhp = g->ennemi[j].e.hp + 1;
    g->ennemi[j].e.data.pos.x = (rand() % ((int) \
    (g->boss[i].e.data.pos.x + 500) - \
    (int) (g->boss[i].e.data.pos.x - 500) + 1) + \
    (int) (g->boss[i].e.data.pos.x - 500));
    g->ennemi[j].e.data.pos.y = (rand() % ((int) \
    (g->boss[i].e.data.pos.y + 500) - \
    (int) (g->boss[i].e.data.pos.y - 500) + 1) + \
    (int) (g->boss[i].e.data.pos.y - 500));
    sfClock_restart(g->boss[i].clock);
}