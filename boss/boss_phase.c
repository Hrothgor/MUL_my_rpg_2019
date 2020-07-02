/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void boss_phase2_2(global_t *g, int i)
{
    g->boss[i].creeps = 0;
    for (int i = 60; i < 65; i++) {
        if (!g->ennemi[i].e.data.init)
            continue;
        g->boss[0].creeps++;
        draw_ennemi(g, i);
        ennemi_attack(g, i);
        move_ennemi(g, i);
        ennemi_death(g, i);
    }
    g->boss[i].invul = 0;
    if (g->boss[i].creeps > 0)
        g->boss[i].invul = 1;
    g->boss[i].e.data.color = (sfColor) {255, 255, 255, 255};
    if (g->boss[i].invul) {
        g->boss[i].e.data.color = (sfColor) {255, 255, 255, 100};
        g->boss[i].e.data.rect.top = 0;
    } else
        g->boss[i].e.data.rect.top = 600;
}

void boss_phase2_creeps(global_t *g, int i)
{
    for (int j = 60; j < 65; j++) {
        g->ennemi[j].ID = j;
        g = init_ennemi2(g, j);
        g = init_mage(g, j);
        g->ennemi[j].e.maxmana = g->ennemi[j].e.mana;
        g->ennemi[j].e.maxhp = g->ennemi[j].e.hp + 1;
        g->ennemi[j].e.data.pos.x = (rand() % \
        ((int) (g->boss[i].e.data.pos.x + 500) - \
        (int) (g->boss[i].e.data.pos.x - 500) + 1) + \
        (int) (g->boss[i].e.data.pos.x - 500));
        g->ennemi[j].e.data.pos.y = (rand() % \
        ((int) (g->boss[i].e.data.pos.y + 500) - \
        (int) (g->boss[i].e.data.pos.y - 500) + 1) + \
        (int) (g->boss[i].e.data.pos.y - 500));
        sfClock_restart(g->boss[i].clock);
    }
}

void boss_phase2(global_t *g, int i)
{
    sfTime time = sfClock_getElapsedTime(g->boss[i].clock);

    g->boss[i].dps = 10;
    g->boss[i].second = time.microseconds / 1000000.0;
    if (g->boss[i].creeps == 0 && g->boss[i].second >= g->boss[i].dps) {
        boss_phase2_creeps(g, i);
    } else if (g->boss[0].creeps > 0)
        sfClock_restart(g->boss[i].clock);
    boss_phase2_2(g, i);
}

void boss_phase1(global_t *g, int i)
{
    sfTime time;

    g->boss[i].dps = 2;
    time = sfClock_getElapsedTime(g->boss[i].clock);
    g->boss[i].second = time.microseconds / 1000000.0;
    if (fabs(sqrt(pow((g->player.e.data.pos.x + 25) - \
    (g->boss[i].e.data.pos.x + \
    (sfTexture_getSize(g->boss[i].e.data.texture).x / 2.0)), 2) + \
    pow((g->player.e.data.pos.y + 25) - (g->boss[i].e.data.pos.y + \
    (sfTexture_getSize(g->boss[i].e.data.texture).x / 2.0)), 2))) <= \
    g->boss[i].range && g->boss[i].second >= g->boss[i].dps) {
        sfClock_restart(g->boss[i].clock);
        fireball_func_boss(g, i);
    }
}
