/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void aoe_update2(global_t *g, gameobject_t *p)
{
    for (int i = 1; i < 45; i++) {
        p[i].pos.x += cosf(p[i].angle) * 5 * p[i].scale.x;
        p[i].pos.y += sinf(p[i].angle) * 5 * p[i].scale.y;
        p[i].scale.x -= 0.02f;
        p[i].scale.y -= 0.02f;
        if (p[i].color.a > 0)
            p[i].color.a -= 5;
        draw_mode(p[i], blend_moden(p[i].texture), g->window);
    }
}

void aoe_dammage(global_t *g, int n)
{
    for (int j = 0; j < 65; j++) {
        if (g->ennemi[j].e.data.init) {
            if ((fabs(sqrt(pow((g->player.e.data.pos.x + 25) - \
            (g->ennemi[j].e.data.pos.x + \
            (g->ennemi[j].e.data.rect.width / 2.0)), 2) + \
            pow((g->player.e.data.pos.y + 25) - (g->ennemi[j].e.data.pos.y + \
            (g->ennemi[j].e.data.rect.width / 2.0)), \
            2))) < 300))
                g->ennemi[j].e.hp -= 4 + (1 * (g->player.e.level / 3));
        }
    }
    aoe_dammage2(g, n);
}

void aoe_update(void *tmp, int n)
{
    global_t *g = tmp;
    gameobject_t *p = g->spell[n].shoot[0].particles;

    if (p[0].pos.x == 0)
        return;
    p[0].scale.x += 0.02f;
    p[0].scale.y += 0.02f;
    p[0].rotation += 5;
    if (p[0].color.a > 0)
        p[0].color.a -= 5;
    draw_mode(p[0], blend_moden(p[0].texture), g->window);
    aoe_update2(g, p);
}

void particles_effect_aoe(global_t *g, int n)
{
    float scale;

    g->spell[n].shoot[0].particles[0].pos.x = g->player.e.data.pos.x + 25;
    g->spell[n].shoot[0].particles[0].pos.y = g->player.e.data.pos.y + 25;
    for (int i = 1; i < 45; i++) {
        g->spell[n].shoot[0].particles[i].color.a = 255;
        g->spell[n].shoot[0].particles[i].pos.x = g->player.e.data.pos.x + 25;
        g->spell[n].shoot[0].particles[i].pos.y = g->player.e.data.pos.y + 25;
        scale = float_rand(1/4, 4/4);
        g->spell[n].shoot[0].particles[i].scale = (v2f) {scale, scale};
        g->spell[n].shoot[0].particles[i].angle = rand() % 360;
    }
}

void aoe_func(void *tmp, int n)
{
    global_t *g = tmp;

    play_sound(g->spell[n].sound, g, 2);
    aoe_dammage(g, n);
    g->spell[n].shoot[0].particles[0].scale = (v2f) {0.5, 0.5};
    g->spell[n].shoot[0].particles[0].rotation = 1;
    g->spell[n].shoot[0].particles[0].color.a = 255;
    particles_effect_aoe(g, n);
}
