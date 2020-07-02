/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void update_map_ui(global_t *g)
{
    static int init = 0;
    static gameobject_t bg;
    static sfCircleShape *circle;

    if (!init++) {
        bg = init_sprite("res/minimap.png", 900, 900, (v2f) {510, 90});
        circle = sfCircleShape_create();
        sfCircleShape_setFillColor(circle, sfRed);
        sfCircleShape_setRadius(circle, 10);
    }
    if (g->ui_map == 1) {
        sfCircleShape_setPosition(circle, (v2f) \
        {(900 * g->player.e.data.pos.x / (4800 * 2)) + g->view_pos.x + 510, \
        (900 * g->player.e.data.pos.y / (4800 * 2)) + g->view_pos.y + 90});
        draw_ui(bg, g->view_pos, g->window);
        sfRenderWindow_drawCircleShape(g->window, circle, NULL);
    }
}