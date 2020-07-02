/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

global_t *init_mage(global_t *g, int i)
{
    g->ennemi[i].e.mana = 100;
    g->ennemi[i].dps = 3;
    g->ennemi[i].agro = 1000;
    g->ennemi[i].range = 700;
    g->ennemi[i].status = 1;
    g->ennemi[i].e.data = init_sprite("res/mage.png", 50, 50, (v2f) {0, 0});
    g->ennemi[i].name = "Mage";
    g->ennemi[i].speed = 3;
    g->ennemi[i].dmg = 50;
    g->ennemi[i].e.hp = 200;
    g->ennemi[i].ranged = 1;
    g->ennemi[i].zone = (sfIntRect) {5264, 7664, 9344, 9184};
    while (inwall_ennemi(g, i)) {
        g->ennemi[i].e.data.pos.x = (rand() % (g->ennemi[i].zone.width - \
        g->ennemi[i].zone.left + 1) + g->ennemi[i].zone.left);
        g->ennemi[i].e.data.pos.y = (rand() % (g->ennemi[i].zone.height - \
        g->ennemi[i].zone.top + 1) + g->ennemi[i].zone.top);
    }
    return (g);
}

global_t *init_wolf(global_t *g, int i)
{
    g->ennemi[i].e.mana = 0;
    g->ennemi[i].dps = 5;
    g->ennemi[i].agro = 500;
    g->ennemi[i].range = 30;
    g->ennemi[i].status = 1;
    g->ennemi[i].e.data = init_sprite("res/wolf.png", 50, 50, \
    (v2f) {0, 0});
    g->ennemi[i].name = "Wolf";
    g->ennemi[i].speed = 6;
    g->ennemi[i].dmg = 15;
    g->ennemi[i].e.hp = 80;
    g->ennemi[i].ranged = 0;
    g->ennemi[i].zone = (sfIntRect) {584, 4952, 4104, 9224};
    while (inwall_ennemi(g, i)) {
        g->ennemi[i].e.data.pos.x = (rand() % (g->ennemi[i].zone.width - \
        g->ennemi[i].zone.left + 1)) + g->ennemi[i].zone.left;
        g->ennemi[i].e.data.pos.y = (rand() % (g->ennemi[i].zone.height - \
        g->ennemi[i].zone.top + 1)) + g->ennemi[i].zone.top;
    }
    return (g);
}

global_t *init_bunny(global_t *g, int i)
{
    g->ennemi[i].e.mana = 0;
    g->ennemi[i].dps = 2;
    g->ennemi[i].agro = 500;
    g->ennemi[i].range = 30;
    g->ennemi[i].status = 0;
    g->ennemi[i].e.data = init_sprite("res/bunny.png", 50, 50, \
    (v2f) {0, 0});
    g->ennemi[i].name = "Bunny";
    g->ennemi[i].speed = 6;
    g->ennemi[i].dmg = 5;
    g->ennemi[i].e.hp = 30;
    g->ennemi[i].ranged = 0;
    g->ennemi[i].zone = (sfIntRect) {4448, 4160, 9216, 5584};
    while (inwall_ennemi(g, i)) {
        g->ennemi[i].e.data.pos.x = (rand() % (g->ennemi[i].zone.width - \
        g->ennemi[i].zone.left + 1)) + g->ennemi[i].zone.left;
        g->ennemi[i].e.data.pos.y = (rand() % (g->ennemi[i].zone.height - \
        g->ennemi[i].zone.top + 1)) + g->ennemi[i].zone.top;
    }
    return (g);
}

global_t *init_ennemi2(global_t *g, int i)
{
    g->ennemi[i].e.data.pos.x = 0;
    g->ennemi[i].e.data.pos.y = 0;
    g->ennemi[i].clock = sfClock_create();
    g->ennemi[i].animation = sfClock_create();
    g->ennemi[i].respawn = sfClock_create();
    g->ennemi[i].second = 0;
    g->ennemi[i].l = init_sprite("res/lifebar.png", 100, 10, (v2f) {0, 0});
    g->ennemi[i].lb = init_sprite("res/lifebar.png", 100, 10, (v2f) {0, 0});
    g->ennemi[i].idle_second = (rand() % 5) + 3;
    g->ennemi[i].idle_time = 0;
    g->ennemi[i].respawn_second = 0;
    g->ennemi[i].e.data.direction = (v2f) {0, 0};
    return (g);
}

void init_ennemi(global_t *g)
{
    g->ennemi = malloc(sizeof(ennemi_t) * 65);
    for (int i = 0; i < 20; i++) {
        g->ennemi[i].ID = i;
        g = init_ennemi2(g, i);
        g = init_wolf(g, i);
        g->ennemi[i].e.maxmana = g->ennemi[i].e.mana;
        g->ennemi[i].e.maxhp = g->ennemi[i].e.hp;
    }
    for (int i = 20; i < 40; i++) {
        g->ennemi[i].ID = i;
        g = init_ennemi2(g, i);
        g = init_mage(g, i);
        g->ennemi[i].e.maxmana = g->ennemi[i].e.mana;
        g->ennemi[i].e.maxhp = g->ennemi[i].e.hp;
    }
    init_ennemi3(g);
}
