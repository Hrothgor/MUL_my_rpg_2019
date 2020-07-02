/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void zone_func(void *tmp, int j)
{
    global_t *g = tmp;
    int n = 9;

    for (int i = 0; i < 40; i++) {
        if (!g->spell[n].shoot[i].init) {
            g->spell[n].shoot[i].init = 1;
            g->spell[n].shoot[i].pos.x = g->ennemi[j].e.data.pos.x + 25;
            g->spell[n].shoot[i].pos.y = g->ennemi[j].e.data.pos.y + 25;
            g->spell[n].shoot[i].angle = atan2((g->player.e.data.pos.y + 25) \
            - g->ennemi[j].e.data.pos.y + 25, \
            (g->player.e.data.pos.x + 25) - g->ennemi[j].e.data.pos.x + 25);
            g->spell[n].shoot[i].direction.x = \
            cosf(g->spell[n].shoot[i].angle) * 20;
            g->spell[n].shoot[i].direction.y = \
            sinf(g->spell[n].shoot[i].angle) * 20;
            init_zone_particles(g, g->spell[n].shoot[i]);
            break;
        }
    }
}

void zone_func_boss2(int r, int n, global_t *g, int num)
{
    for (int i = 0; i < 40; i++) {
        if (!g->spell[n].shoot[i].init) {
            g->spell[n].shoot[i].init = 1;
            g->spell[n].shoot[i].pos.x = (rand() % ((int) \
            (g->boss[0].e.data.pos.x + 500) - \
            (int) (g->boss[0].e.data.pos.x - 500) + 1) + (int) \
            (g->boss[0].e.data.pos.x - 500));
            g->spell[n].shoot[i].pos.y = (rand() % ((int) \
            (g->boss[0].e.data.pos.y + 500) - \
            (int) (g->boss[0].e.data.pos.y - 500) + 1) + (int) \
            (g->boss[0].e.data.pos.y - 500));
            init_zone_particles(g, g->spell[n].shoot[i]);
            r++;
            if (r > num)
                break;
        }
    }
}

void zone_func_boss(void *tmp, int j)
{
    global_t *g = tmp;
    int n = 9;
    int num = (rand() % 4) + 1;
    int r = 0;

    zone_func_boss2(r, n, g, num);
}

spell_t init_zone2(spell_t s)
{
    s.clock = sfClock_create();
    s.second = 0;
    s.progress = 0;
    s.cooldown = 0.2;
    s.key = 2;
    s.UI = init_sprite("res/spell_frostbolt.png", 80, 80, (v2f) {800, 800});
    s.UI.image = sfImage_createFromFile("res/spell_frostbolt.png");
    s.UI.func = zone_func;
    s.UI.update = zone_update;
    s.shoot = malloc(sizeof(gameobject_t) * 40);
    return (s);
}

spell_t init_zone(void)
{
    spell_t s;

    s = init_zone2(s);
    for (int i = 0; i < 40; i++) {
        s.shoot[i] = init_sprite("res/area.png", 512, 512, (v2f) {0, 0});
        s.shoot[i].init = 0;
        s.shoot[i].particles = malloc(sizeof(gameobject_t) * 40);
        for (int j = 0; j < 40; j++) {
            s.shoot[i].particles[j] = init_sprite(\
            "res/depo0.png", 32, 32, (v2f) {0, 0});
            s.shoot[i].particles[j].init = 0;
        }
    }
    return (s);
}
