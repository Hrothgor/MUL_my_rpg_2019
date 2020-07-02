/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void explosion_update4(void *tmp, int n)
{
    global_t *g = tmp;
    gameobject_t *p = g->spell[n].shoot[0].particles;

    for (int i = 20; i < 34; i++) {
        if (p[i].color.a > 0)
            p[i].color.a -= 8;
        p[i].scale.x += 0.2f;
        p[i].scale.y += 0.2f;
        if (p[i].rotation < 0)
            p[i].rotation--;
        else
            p[i].rotation++;
        draw_mode(p[i], blend_moden(p[i].texture), g->window);
    }
}

void explosion_update3(void *tmp, int n)
{
    global_t *g = tmp;
    gameobject_t *p = g->spell[n].shoot[0].particles;

    if (g->spell[n].state == 2) {
        explosion_update4(tmp, n);
        update_explosion_particles2(g, p);
        update_explosion_particles3(g, p);
        if (p[34].color.a > 0)
            p[34].color.a -= 10;
        p[34].scale.x += 1.0;
        p[34].scale.y += 1.0;
        draw_mode(p[34], blend_moden(p[34].texture), g->window);
    }
}

void explosion_update2(void *tmp, int n)
{
    global_t *g = tmp;
    gameobject_t *p = g->spell[n].shoot[0].particles;

    if (p[1].scale.x > 1.3) {
        p[1].scale.x -= 0.02f;
        p[1].scale.y -= 0.02f;
    } else {
        g->spell[n].state = 2;
        play_sound(g->spell[n].sound2, g, 2);
        explosion_dammage(g, n);
    }
    if (p[0].color.a < 255)
        p[0].color.a += 5;
    if (p[1].color.a < 255)
        p[1].color.a += 5;
}

void explosion_update(void *tmp, int n)
{
    global_t *g = tmp;
    gameobject_t *p = g->spell[n].shoot[0].particles;

    if (g->spell[n].state == 1) {
        explosion_update2(tmp, n);
        p[2].color.a += 3;
        p[2].scale.x += 0.02f;
        p[2].scale.y += 0.02f;
        p[0].rotation += 2;
        p[1].rotation -= 4;
        p[3].rotation += 2;
        p[4].rotation -= 4;
        for (int i = 0; i < 5; i++)
            draw_mode(p[i], blend_moden(p[i].texture), g->window);
        update_explosion_particles(g, p);
    }
    explosion_update3(tmp, n);
}
