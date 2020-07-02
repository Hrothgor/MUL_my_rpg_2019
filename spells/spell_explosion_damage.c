/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void explosion_dammage3(global_t *g,  gameobject_t *p)
{
    for (int i = 0; i < 1; i++) {
        if (!g->boss[i].e.data.init)
            continue;
        if ((fabs(sqrt(pow((p[0].pos.x + 128) - (g->boss[i].e.data.pos.x + \
        (g->boss[i].e.data.rect.width / 2.0)), 2) + \
        pow((p[0].pos.y + 128) - (g->boss[i].e.data.pos.y + \
        (g->boss[i].e.data.rect.width / 2.0)), 2))) < 500) \
        && !g->boss[i].invul)
            g->boss[i].e.hp -= 10 + (3 * g->player.e.level);
    }
}

void explosion_dammage2(global_t *g, int i)
{
    if (g->ennemi[i].e.hp <= 0) {
        drop_items(g->ennemi[i], g);
        g->ennemi[i].e.data.init = 0;
    }
    if (g->ennemi[i].e.hp <= 0) {
        drop_items(g->ennemi[i], g);
        g->ennemi[i].e.data.init = 0;
    }
    if (g->ennemi[i].e.hp <= 0) {
        drop_items(g->ennemi[i], g);
        g->ennemi[i].e.data.init = 0;
    }
    if (g->ennemi[i].e.hp <= 0) {
        drop_items(g->ennemi[i], g);
        g->ennemi[i].e.data.init = 0;
    }
}

void explosion_dammage(global_t *g, int n)
{
    gameobject_t *p = g->spell[n].shoot[0].particles;

    for (int i = 0; i < 65; i++) {
        if (!g->ennemi[i].e.data.init)
            continue;
        if ((fabs(sqrt(pow((p[0].pos.x + 128) - (g->ennemi[i].e.data.pos.x + \
        (g->ennemi[i].e.data.rect.width / 2.0)), 2) + \
        pow((p[0].pos.y + 128) - (g->ennemi[i].e.data.pos.y + \
        (g->ennemi[i].e.data.rect.width / 2.0)), 2))) < 500))
            g->ennemi[i].e.hp -= 10 + (3 * g->player.e.level);
        explosion_dammage2(g, i);
    }
    explosion_dammage3(g, p);
}