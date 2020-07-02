/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void init_ennemi3(global_t *g)
{
    for (int i = 40; i < 65; i++) {
        g->ennemi[i].ID = i;
        g = init_ennemi2(g, i);
        g = init_bunny(g, i);
        g->ennemi[i].e.maxmana = g->ennemi[i].e.mana;
        g->ennemi[i].e.maxhp = g->ennemi[i].e.hp;
    }
}
