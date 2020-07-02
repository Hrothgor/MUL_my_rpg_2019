/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void update_shield_particles3(global_t *g, gameobject_t *p, int i)
{
    if (p[i].init) {
        p[i].scale.x -= 0.02f;
        p[i].scale.y -= 0.02f;
        if (p[i].rotation < 0)
            p[i].rotation--;
        else
            p[i].rotation++;
        p[i].pos.y--;
        if (p[i].color.a > 0)
            p[i].color.a -= 5;
        if (p[i].color.a <= 0)
            p[i].init = 0;
        draw_mode(p[i], \
        blend_moden(p[i].texture), g->window);
    }
}

void update_shield_particles2(global_t *g, gameobject_t *p)
{
    for (int i = 7; i < 20; i++) {
        if (!p[i].init) {
            p[i].pos.x = rand() % (int) ((g->player.e.data.pos.x + 80) - \
            (g->player.e.data.pos.x - 32)) + (g->player.e.data.pos.x - 32);
            p[i].pos.y = rand() % (int) ((g->player.e.data.pos.y + 80) - \
            (g->player.e.data.pos.y - 32)) + (g->player.e.data.pos.y - 32);
            p[i].init = 1;
            p[i].scale.y = 0.8;
            p[i].scale.x = 0.8;
            p[i].color.a = 200;
        }
    }
}

void update_shield_particles(global_t *g, gameobject_t *p)
{
    for (int i = 2; i < 7; i++) {
        p[i].pos = g->player.e.data.pos;
        p[i].scale.x = 1.4;
        p[i].scale.y = 1.4;
        p[i].rotation -= 3;
        p[i].color.a = 255 - 51 * (i - 2);
        p[i].pos.x = g->player.e.data.pos.x + 25;
        p[i].pos.y = g->player.e.data.pos.y + 25;
        draw_mode(p[i], \
        blend_moden(p[i].texture), g->window);
    }
    update_shield_particles2(g, p);
    for (int i = 7; i < 20; i++)
        update_shield_particles3(g, p, i);
}

void shield_update(void *tmp, int n)
{
    global_t *g = tmp;
    static float s = 0;
    gameobject_t *p = g->spell[n].shoot[0].particles;

    if (g->player.shield) {
        s += 0.02f;
        p[0].pos.x = g->player.e.data.pos.x + 25;
        p[0].pos.y = g->player.e.data.pos.y + 25;
        p[1].pos.x = g->player.e.data.pos.x + 25;
        p[1].pos.y = g->player.e.data.pos.y + 25;
        p[1].scale.x += cos(s) / 100;
        p[1].scale.y += cos(s) / 100;
        p[1].color.a = 100;
        p[0].rotation += 1;
        p[1].rotation -= 2;
        draw_mode(p[0], blend_moden(p[0].texture), g->window);
        draw_mode(p[1], blend_moden(p[1].texture), g->window);
        update_shield_particles(g, p);
    }
}

void shield_func(void *tmp, int n)
{
    global_t *g = tmp;
    play_sound(g->spell[n].sound, g, 2);
    g->player.shield = 1;
}
