/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void update_explosion_particles(global_t *g, gameobject_t *p)
{
    for (int i = 5; i < 20; i++) {
        p[i].pos = g->player.e.data.pos;
        p[i].color.a = 100;
        p[i].scale.x = 3.0 - (0.2 * i);
        p[i].scale.y = 3.0 - (0.2 * i);
        p[i].rotation += 4;
        p[i].pos = p[0].pos;
        draw_mode(p[i], blend_moden(p[i].texture), g->window);
    }
}

void update_explosion_particles2(global_t *g, gameobject_t *p)
{
    for (int i = 35; i < 55; i++) {
        p[i].scale.x -= 0.001f;
        p[i].scale.y -= 0.001f;
        p[i].pos.y -= p[i].direction.y;
        if (p[i].color.a > 0)
            p[i].color.a -= 1;
        if (p[i].rotation < 0)
            p[i].rotation--;
        else
            p[i].rotation++;
        draw_mode(p[i], blend_moden(p[i].texture), g->window);
    }
}

void update_explosion_particles3(global_t *g, gameobject_t *p)
{
    for (int i = 55; i < 100; i++)
        update_explosion_particles4(g, p, i);
}

void update_explosion_particles4(global_t *g, gameobject_t *p, int i)
{
    if (p[i].init) {
        p[i].pos.x += cosf(p[i].angle) * \
        5 * p[i].scale.x;
        p[i].pos.y += sinf(p[i].angle) * 5 \
        * p[i].scale.y;
        if (p[i].color.a > 0)
            p[i].color.a -= 2;
        draw_mode(p[i], \
        blend_moden(p[i].texture), g->window);
    }
}
