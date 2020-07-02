/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void blink_update3(global_t *g, gameobject_t *p)
{
    p[4].pos.x = (g->player.end_pos.x + g->player.begin_pos.x) / 2;
    p[4].pos.y = (g->player.end_pos.y + g->player.begin_pos.y) / 2;
    p[4].rotation = (g->player.e.data.angle * (180 / M_PI)) + 90;
    if (p[4].color.a > 0)
        p[4].color.a -= 5;
    if (p[4].color.a > 0)
        p[4].color.a -= 5;
    draw_mode(p[4], blend_moden(p[4].texture), g->window);
    for (int i = 5; i < 45; i++) {
        p[i].pos.x += cosf(p[i].angle) * 5 * p[i].scale.x;
        p[i].pos.y += sinf(p[i].angle) * 5 * p[i].scale.y;
        p[i].scale.x -= 0.02f;
        p[i].scale.y -= 0.02f;
        if (p[i].color.a > 0)
            p[i].color.a -= 5;
        draw_mode(p[i], blend_moden(p[i].texture), g->window);
    }
}

void blink_update2(global_t *g, gameobject_t *p)
{
    p[2].pos = g->player.begin_pos;
    p[3].pos = g->player.end_pos;
    p[2].scale.x -= 0.02f;
    p[2].scale.y -= 0.02f;
    p[3].scale.x += 0.02f;
    p[3].scale.y += 0.02f;
    p[2].rotation += 5;
    p[3].rotation -= 5;
    if (p[2].color.a > 0)
        p[2].color.a -= 5;
    if (p[3].color.a > 0)
        p[3].color.a -= 5;
    draw_mode(p[2], blend_moden(p[2].texture), g->window);
    draw_mode(p[3], blend_moden(p[3].texture), g->window);
    blink_update3(g, p);
}

void blink_update(void *tmp, int n)
{
    global_t *g = tmp;
    gameobject_t *p = g->spell[n].shoot[0].particles;

    if (p[0].color.a == 0)
        return;
    p[0].pos = g->player.begin_pos;
    p[1].pos = g->player.end_pos;
    p[0].scale.x -= 0.02f;
    p[0].scale.y -= 0.02f;
    p[1].scale.x += 0.02f;
    p[1].scale.y += 0.02f;
    p[0].rotation += 5;
    p[1].rotation -= 5;
    if (p[0].color.a > 0)
        p[0].color.a -= 5;
    if (p[1].color.a > 0)
        p[1].color.a -= 5;
    draw_mode(p[0], blend_moden(p[0].texture), g->window);
    draw_mode(p[1], blend_moden(p[1].texture), g->window);
    blink_update2(g, p);
}
