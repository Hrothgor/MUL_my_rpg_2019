/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void heal_update(void *tmp, int n)
{
    global_t *g = tmp;

    for (int i = 0; i < 20; i++) {
        if (g->spell[n].shoot[0].particles[i].color.a == 0)
            continue;
        g->spell[n].shoot[0].particles[i].pos.x += \
        cosf(g->spell[n].shoot[0].particles[i].angle)\
        * 5 * g->spell[n].shoot[0].particles[i].scale.x;
        g->spell[n].shoot[0].particles[i].pos.y += \
        sinf(g->spell[n].shoot[0].particles[i].angle)\
        * 5 * g->spell[n].shoot[0].particles[i].scale.y;
        g->spell[n].shoot[0].particles[i].scale.x -= 0.02f;
        g->spell[n].shoot[0].particles[i].scale.y -= 0.02f;
        if (g->spell[n].shoot[0].particles[i].color.a > 0)
            g->spell[n].shoot[0].particles[i].color.a -= 5;
        draw_mode(g->spell[n].shoot[0].particles[i], \
        blend_moden(g->spell[n].shoot[0].particles[i].texture), g->window);
    }
}

void particles_effect_heal(global_t *g, int n)
{
    float scale;

    for (int i = 0; i < 20; i++) {
        g->spell[n].shoot[0].particles[i].angle = rand() % 360;
        g->spell[n].shoot[0].particles[i].color.a = 255;
        g->spell[n].shoot[0].particles[i].pos.x = g->player.e.data.pos.x + 25;
        g->spell[n].shoot[0].particles[i].pos.y = g->player.e.data.pos.y + 25;
        scale = float_rand(1/4, 4/4);
        g->spell[n].shoot[0].particles[i].scale = (v2f) {scale, scale};
    }
}

void heal_func(void *tmp, int n)
{
    global_t *g = tmp;

    g->player.e.hp += (g->player.e.maxhp * 20) / 100;
    play_sound(g->spell[n].sound, g, 2);
    particles_effect_heal(g, n);
}
