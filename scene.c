/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void scene_0(global_t *g)
{
    static int init = 0;
    static gameobject_t bg;

    if (!init++)
        bg = init_sprite("res/menu_background.png", 1920, 1080, (v2f) {0, 0});
    draw_ui(bg, g->view_pos, g->window);
}

void scene_1(global_t *g)
{
    draw(g->map.bottom, g->window);
    draw(g->map.bottom2, g->window);
    g->player.map = g->player.e.data.pos.x > 10000 ? 2 : 1;
    update_ennemi(g);
    update_pnj(g);
    update_boss(g);
    update_player(g);
    draw(g->map.top, g->window);
    draw(g->map.top2, g->window);
    update_frame(g);
    update_ui(g);
}

void scene_2(global_t *g)
{
    static int init = 0;
    static gameobject_t bg;
    static gameobject_t bg1;

    if (!init++) {
        bg = init_sprite("res/menu_background.png", 1920, 1080, (v2f) {0, 0});
        bg1 = init_sprite("res/sys_back.png", 1300, 920, (v2f) {250, 100});
    }
    draw_ui(bg, g->view_pos, g->window);
    draw_ui(bg1, g->view_pos, g->window);
    update_slider_0(g);
    update_slider_1(g);
    update_slider_2(g);
    update_slider_3(g);
}

void scene_3(global_t *g)
{
    static int init = 0;
    static gameobject_t bg;
    static gameobject_t bg1;

    if (!init++) {
        bg = init_sprite("res/menu_background.png", 1920, 1080, (v2f) {0, 0});
        bg1 = init_sprite("res/sys_back.png", 1300, 9200, (v2f) {250, 100});
    }
    draw_ui(bg, g->view_pos, g->window);
    draw_ui(bg1, g->view_pos, g->window);
    update_slider_key(g);
    update_key_change(g);
}

void scene_4(global_t *g)
{
    static int init = 0;
    static gameobject_t bg[2];

    if (!init++) {
        bg[0] = init_sprite("res/dress_human.png", 1920, 1080, (v2f) {0, 0});
        bg[1] = init_sprite("res/dress_orc.png", 1920, 1080, (v2f) {0, 0});
    }
    draw_ui(bg[g->player.race], g->view_pos, g->window);
    update_save_back(g);
}
