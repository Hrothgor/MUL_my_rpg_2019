/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void sickle_func(void *tmp, int j)
{
    global_t *g = tmp;
    int n = 7;

    play_sound(g->spell[n].sound, g, 2);
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
            init_sickle_particles(g, g->spell[n].shoot[i]);
            break;
        }
    }
}

void sickle_func_boss2(global_t *g, int j, int n, int r)
{
    for (int i = 0; i < 40; i++) {
        if (!g->spell[n].shoot[i].init) {
            g->spell[n].shoot[i].init = 1;
            g->spell[n].shoot[i].pos.x = g->boss[j].e.data.pos.x + 25;
            g->spell[n].shoot[i].pos.y = g->boss[j].e.data.pos.y + 25;
            g->spell[n].shoot[i].angle = atan2((g->player.e.data.pos.y + 25) \
            - g->boss[j].e.data.pos.y + 25, \
            (g->player.e.data.pos.x + 25) - g->boss[j].e.data.pos.x + 25);
            g->spell[n].shoot[i].angle += (M_PI / 8) * r;
            g->spell[n].shoot[i].direction.x = \
            cosf(g->spell[n].shoot[i].angle) * 20;
            g->spell[n].shoot[i].direction.y = \
            sinf(g->spell[n].shoot[i].angle) * 20;
            init_sickle_particles(g, g->spell[n].shoot[i]);
            r++;
            if (r == 16)
                break;
        }
    }
}

void sickle_func_boss(void *tmp, int j)
{
    global_t *g = tmp;
    int n = 7;
    int r = 0;

    play_sound(g->spell[n].sound, g, 2);
    sickle_func_boss2(g, j, n, r);
}

spell_t init_sickle2(spell_t s)
{
    s.clock = sfClock_create();
    s.second = 0;
    s.progress = 0;
    s.cooldown = 0.2;
    s.key = 2;
    s.mana = 0;
    s.sound = create_sound("res/sickle");
    s.UI = init_sprite("res/spell_frostbolt.png", 80, 80, (v2f) {800, 800});
    s.UI.image = sfImage_createFromFile("res/spell_frostbolt.png");
    s.UI.func = sickle_func;
    s.UI.update = sickle_update;
    s.shoot = malloc(sizeof(gameobject_t) * 40);
    return (s);
}

spell_t init_sickle(void)
{
    spell_t s;

    s = init_sickle2(s);
    for (int i = 0; i < 40; i++) {
        s.shoot[i] = init_sprite("res/sickle.png", 64, 64, (v2f) {0, 0});
        s.shoot[i].init = 0;
        s.shoot[i].particles = malloc(sizeof(gameobject_t) * 40);
        for (int j = 0; j < 40; j++) {
            s.shoot[i].particles[j] = init_sprite(\
            "res/particles_2.png", 64, 64, (v2f) {0, 0});
            s.shoot[i].particles[j].init = 0;
        }
    }
    return (s);
}
