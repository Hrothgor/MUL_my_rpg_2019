/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void aoe_dammage2(global_t *g, int n)
{
    for (int j = 0; j < 1; j++) {
        if (g->boss[j].e.data.init) {
            if ((fabs(sqrt(pow((g->player.e.data.pos.x + 25) - \
            (g->boss[j].e.data.pos.x + \
            (g->boss[j].e.data.rect.width / 2.0)), 2) + \
            pow((g->player.e.data.pos.y + 25) - (g->boss[j].e.data.pos.y + \
            (g->boss[j].e.data.rect.width / 2.0)), \
            2))) < 300) && !g->boss[j].invul)
                g->boss[j].e.hp -= 4 + (1 * (g->player.e.level / 3));
        }
    }
}