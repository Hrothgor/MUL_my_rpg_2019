/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** Map updater function
*/

#include "function.h"

void init_boss2(global_t *g)
{
    g->boss[0].dmg = 50;
    g->boss[0].dps = 10;
    g->boss[0].agro = 500;
    g->boss[0].range = 1000;
    g->boss[0].e.level = 50;
    g->boss[0].e.mana = 1000;
    g->boss[0].e.maxmana = g->boss[0].e.mana;
    g->boss[0].e.hp = 4000;
    g->boss[0].e.maxhp = g->boss[0].e.hp;
    g->boss[0].e.name = "Ragnarog";
    g->boss[0].e.data = init_sprite("res/boss.png", 150, 150, \
    (v2f) {20725, 20500});
    g->boss[0].l = init_sprite("res/bossbar.png", 998, 60, (v2f) {551, 60});
    g->boss[0].lb = init_sprite("res/bossbarbg.png", 998, 60, (v2f) {461, 60});
}

void init_boss(global_t *g)
{
    g->boss = malloc(sizeof(ennemi_t) * 1);
    g->boss[0].clock = sfClock_create();
    g->boss[0].animation = sfClock_create();
    g->boss[0].second = 0;
    g->boss[0].phase = 0;
    g->boss[0].ID = 0;
    g->boss[0].name = "Ragnarog";
    g->boss[0].xp = 1000;
    g->boss[0].speed = 3;
    g->boss[0].invul = 0;
    g->boss[0].creeps = 0;
    init_boss2(g);
}
