/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void update_game(global_t *g)
{
    if (g->scene != 1 && g->scene != 4 && g->scene != 5 && g->scene != 6)
        particles_effect_scene_0(g);
    text_middle(g);
    g->view_pos.x = g->player.e.data.pos.x - 960;
    g->view_pos.y = g->player.e.data.pos.y - 540;
    sfView_reset(g->view, (sfFloatRect) \
    {g->view_pos.x, g->view_pos.y, 1920, 1080});
    sfRenderWindow_setView(g->window, g->view);
}

void game(global_t *g)
{
    if (g->scene == 0)
        scene_0(g);
    if (g->scene == 1)
        scene_1(g);
    if (g->scene == 2)
        scene_2(g);
    if (g->scene == 3)
        scene_3(g);
    if (g->scene == 4)
        scene_4(g);
    if (g->scene == 5)
        scene_5(g);
    if (g->scene == 6)
        scene_6(g);
    if (g->scene == 7)
        scene_7(g);
    if (g->scene == 8)
        scene_8(g);
    update_game(g);
}

void button_event(global_t *g)
{
    int scene = g->scene;

    for (int i = 0; g->button[scene][i].init; i++) {
        if (hover_button_ui(g->button[scene][i], g->window, g)) {
            g->button[g->scene][i].rect.left = \
            g->button[g->scene][i].rect.width;
            if (g->event.mouseLdown)
                g->button[scene][i].rect.left = \
                2 * g->button[g->scene][i].rect.width;
            if (g->event.mouseLup)
                g->button[scene][i].func(g, i);
        } else {
            g->button[scene][i].rect.left = 0;
        }
        draw_ui(g->button[scene][i], g->view_pos, g->window);
    }
}

void update(sfRenderWindow *window, sfEvent event)
{
    global_t *g = init_global(window);

    play_sound(g->song, g, 1);
    while (sfRenderWindow_isOpen(g->window)) {
        sfRenderWindow_clear(g->window, sfBlack);
        play_sound(g->song, g, 3);
        poll_event(g, event);
        game(g);
        button_event(g);
        sfRenderWindow_display(g->window);
    }
}
