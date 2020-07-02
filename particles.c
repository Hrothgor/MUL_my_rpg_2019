/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void particles_effect_scene_0(global_t *g)
{
    static int init = 0;
    static gameobject_t p[200];
    sfVector2f pos;
    float scale = 0;

    if (!init++) {
        for (int i = 0; i < 100; i++) {
            pos.x = rand() % 2520 - 800;
            pos.y = rand() % 1080;
            p[i] = init_sprite("res/particles_0.png", 64, 64, pos);
            scale = float_rand(1/4, 4/4);
            p[i].scale = (v2f) {scale, scale};
        }
    }
    for (int i = 0; i < 100; i++) {
        p[i].pos.y -= (p[i].scale.y * 4) / 2;
        p[i].pos.x += cosf(p[i].pos.y / 100) * (p[i].scale.x * 4) / 5;
        p[i].pos.y = p[i].pos.y < -64 ? 1100 : p[i].pos.y;
        draw_mode_ui(p[i], g->view_pos, blend_mode(p[i].texture), g->window);
    }
}
