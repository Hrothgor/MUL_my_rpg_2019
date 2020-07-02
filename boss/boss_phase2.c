/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void boss_phase4(global_t *g, int i)
{
    sfTime time = sfClock_getElapsedTime(g->boss[i].clock);

    g->boss[i].dps = 5;
    g->boss[i].second = time.microseconds / 1000000.0;
    if (fabs(sqrt(pow((g->player.e.data.pos.x + 25) - \
    (g->boss[i].e.data.pos.x + \
    (sfTexture_getSize(g->boss[i].e.data.texture).x / 2.0)), 2) + \
    pow((g->player.e.data.pos.y + 25) - (g->boss[i].e.data.pos.y + \
    (sfTexture_getSize(g->boss[i].e.data.texture).x / 2.0)), 2))) <= \
    g->boss[i].range && g->boss[i].second >= g->boss[i].dps) {
        sfClock_restart(g->boss[i].clock);
        ring_func(g, 8);
        sickle_func_boss(g, i);
        fireball_func_boss(g, i);
    }
}

void boss_phase3(global_t *g, int i)
{
    sfTime time = sfClock_getElapsedTime(g->boss[i].clock);

    g->boss[i].dps = 5;
    g->boss[i].second = time.microseconds / 1000000.0;
    if (fabs(sqrt(pow((g->player.e.data.pos.x + 25) - \
    (g->boss[i].e.data.pos.x + \
    (sfTexture_getSize(g->boss[i].e.data.texture).x / 2.0)), 2) + \
    pow((g->player.e.data.pos.y + 25) - (g->boss[i].e.data.pos.y + \
    (sfTexture_getSize(g->boss[i].e.data.texture).x / 2.0)), 2))) <= \
    g->boss[i].range && g->boss[i].second >= g->boss[i].dps) {
        sfClock_restart(g->boss[i].clock);
        zone_func_boss(g, i);
        sickle_func_boss(g, i);
    }
}
