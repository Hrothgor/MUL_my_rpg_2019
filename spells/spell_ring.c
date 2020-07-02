/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void ring_update2(global_t *g, gameobject_t *p)
{
    for (int i = 1; i < 40; i++) {
        p[i].pos.x += cosf(p[i].angle) * 5 * p[i].scale.x;
        p[i].pos.y += sinf(p[i].angle) * 5 * p[i].scale.y;
        p[i].scale.x -= 0.001f;
        p[i].scale.y -= 0.001f;
        if (p[i].color.a > 0)
            p[i].color.a -= 1;
        draw_mode(p[i], blend_moden(p[i].texture), g->window);
    }
}

void ring_dammage(global_t *g, int n)
{
    gameobject_t *p = g->spell[n].shoot[0].particles;

    if ((fabs(sqrt(pow((g->player.e.data.pos.x + 25) - \
    (g->boss[0].e.data.pos.x + 50), 2) + \
    pow((g->player.e.data.pos.y + 25) - (g->boss[0].e.data.pos.y + 100), \
    2))) < (256*p[0].scale.x)) && (fabs(sqrt(pow(\
    (g->player.e.data.pos.x + 25) - (g->boss[0].e.data.pos.x + 50), 2) + \
    pow((g->player.e.data.pos.y + 25) - (g->boss[0].e.data.pos.y + 100), \
    2))) > (256*p[0].scale.x - 50*p[0].scale.x))) {
        if (g->player.shield) {
            g->player.shield = 0;
        } else {
            g->player.e.hp -= 1000;
        }
    }
}

void ring_update(void *tmp, int n)
{
    global_t *g = tmp;
    gameobject_t *p = g->spell[n].shoot[0].particles;

    if (p[0].pos.x == 0)
        return;
    p[0].scale.x += 0.02f;
    p[0].scale.y += 0.02f;
    p[0].rotation += 5;
    if (p[0].color.a > 0) {
        ring_dammage(g, n);
        p[0].color.a -= 1;
    }
    draw_mode(p[0], blend_moden(p[0].texture), g->window);
    ring_update2(g, p);
}

void particles_effect_ring(global_t *g, int n)
{
    float scale;

    g->spell[n].shoot[0].particles[0].pos.x = g->boss[0].e.data.pos.x + 50;
    g->spell[n].shoot[0].particles[0].pos.y = g->boss[0].e.data.pos.y + 100;
    for (int i = 1; i < 40; i++) {
        g->spell[n].shoot[0].particles[i].color.a = 255;
        g->spell[n].shoot[0].particles[i].pos.x = g->boss[0].e.data.pos.x + 50;
        g->spell[n].shoot[0].particles[i].pos.y = g->boss[0].e.data.pos.y + 100;
        scale = float_rand(1/4, 4/4);
        g->spell[n].shoot[0].particles[i].scale = (v2f) {scale, scale};
        g->spell[n].shoot[0].particles[i].angle = rand() % 360;
    }
}

void ring_func(void *tmp, int n)
{
    global_t *g = tmp;

    sfSound_play(g->spell[n].sound);
    g->spell[n].shoot[0].particles[0].scale = (v2f) {0.5, 0.5};
    g->spell[n].shoot[0].particles[0].rotation = 1;
    g->spell[n].shoot[0].particles[0].color.a = 255;
    particles_effect_ring(g, n);
}
