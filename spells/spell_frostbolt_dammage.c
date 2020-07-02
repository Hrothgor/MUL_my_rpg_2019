/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void frostbolt_dammage2(global_t *g, int n, int i)
{
    for (int j = 0; j < 1; j++) {
        if (g->boss[j].e.data.init) {
            if ((fabs(sqrt(pow((g->spell[n].shoot[i].pos.x) - \
            (g->boss[j].e.data.pos.x + \
            (g->boss[j].e.data.rect.width / 2.0)), 2) + \
            pow((g->spell[n].shoot[i].pos.y) - (g->boss[j].e.data.pos.y + \
            (g->boss[j].e.data.rect.width / 2.0)), \
            2))) < 100) && g->spell[n].shoot[i].init && !g->boss[j].invul) {
                g->boss[j].e.hp -= 1 + (1 * (g->player.e.level / 3));
                g->spell[n].shoot[i].init = 0;
            }
        }
    }
}

void frostbolt_dammage(global_t *g, int n, int i)
{
    for (int j = 0; j < 65; j++) {
        if (g->ennemi[j].e.data.init) {
            if ((fabs(sqrt(pow((g->spell[n].shoot[i].pos.x) - \
            (g->ennemi[j].e.data.pos.x + \
            (g->ennemi[j].e.data.rect.width / 2.0)), 2) + \
            pow((g->spell[n].shoot[i].pos.y) - (g->ennemi[j].e.data.pos.y + \
            (g->ennemi[j].e.data.rect.width / 2.0)), \
            2))) < 100) && g->spell[n].shoot[i].init) {
                g->ennemi[j].e.hp -= 1 + (1 * (g->player.e.level / 3));
                g->spell[n].shoot[i].init = 0;
            }
        }
    }
    frostbolt_dammage2(g, n, i);
}