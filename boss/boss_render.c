/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void draw_blife(boss_t g, sfRenderWindow *window, global_t *glo)
{
    if (g.phase > 0) {
        g.l.rect.left = 90;
        g.l.rect.width = 815 * (g.e.hp / g.e.maxhp);
        draw_ui(g.lb, glo->view_pos, window);
        draw_ui(g.l, glo->view_pos, window);
        draw_bname(g, glo->window, glo);
    }
}

void draw_bname(boss_t g, sfRenderWindow *window, global_t *glo)
{
    static int init = 0;
    static text_info_t text;

    if (!init++)
        text = init_text_sys(48, NULL, (v2f) {880, 0});
    text.data = g.name;
    draw_text_ui(text, glo->view_pos, glo->window);
}

void draw_boss(global_t *g, int i)
{
    draw(g->boss[i].e.data, g->window);
    draw_blife(g->boss[i], g->window, g);
}

void boss_animation(global_t *g, float angle)
{
    sfTime time;
    float second = 0;
    float trigo = sqrtf(2) / 2;

    time = sfClock_getElapsedTime(g->boss[0].animation);
    second = time.microseconds / 1000000.0;
    if (cosf(angle) > trigo)
        g->boss[0].e.data.rect.top = 300;
    if (cosf(angle) < -trigo)
        g->boss[0].e.data.rect.top = 150;
    if (cosf(angle) > -trigo && cosf(angle) < trigo && sinf(angle) < 0)
        g->boss[0].e.data.rect.top = 450;
    if (cosf(angle) > -trigo && cosf(angle) < trigo && sinf(angle) > 0)
        g->boss[0].e.data.rect.top = 0;
    if (second > 0.2) {
        move_rect(&g->boss[0].e.data.rect, 150, 0, 600);
        sfClock_restart(g->boss[0].animation);
    }
}
