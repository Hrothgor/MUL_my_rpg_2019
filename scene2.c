/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void scene_5(global_t *g)
{
    static int init = 0;
    static gameobject_t bg[2];

    if (!init++) {
        bg[0] = init_sprite("res/dress_human.png", 1920, 1080, (v2f) {0, 0});
        bg[1] = init_sprite("res/dress_orc.png", 1920, 1080, (v2f) {0, 0});
    }
    draw_ui(bg[g->player.race], g->view_pos, g->window);
    enter_name(g);
    draw_preview(g);
}

void scene_6(global_t *g)
{
    static int init = 0;
    static gameobject_t bg;

    if (!init++)
        bg = init_sprite("res/pausebg.png", 1920, 1080, (v2f) {0, 0});
    draw_ui(bg, g->view_pos, g->window);
}

void scene_7(global_t *g)
{
    static int init = 0;
    static gameobject_t bg;

    if (!init++)
        bg = init_sprite("res/gg.png", 1920, 1080, (v2f) {0, 0});
    draw_ui(bg, g->view_pos, g->window);
}

void scene_8(global_t *g)
{
    static int init = 0;
    static gameobject_t bg;

    if (!init++)
        bg = init_sprite("res/htp.png", 1920, 1080, (v2f) {0, 0});
    draw_ui(bg, g->view_pos, g->window);
}