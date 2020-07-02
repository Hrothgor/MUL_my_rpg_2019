/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void draw_save(global_t *g)
{
    static int init = 0;
    static text_info_t text1;
    static text_info_t text2;

    if (!init++) {
        text1 = init_text_sys(30, NULL, (v2f) {1490, 75});
        text2 = init_text_sys(24, NULL, (v2f) {1490, 115});
        text2.color = sfWhite;
    }
    for (int i = 0; g->save[i].bg.init; i++) {
        text1.data = my_strdup(g->save[i].data.e.name);
        text1.pos.y = 75 + 100 * i;
        text2.data = my_strcat("Niveau ", my_itostr(g->save[i].data.e.level));
        text2.pos.y = 115 + 100 * i;
        draw_text_ui(text1, g->view_pos, g->window);
        draw_text_ui(text2, g->view_pos, g->window);
        free(text1.data);
        free(text2.data);
    }
}

void update_save_selection(global_t *g)
{
    for (int i = 0; g->save[i].bg.init; i++) {
        if (hover_button_ui(g->save[i].bg, g->window, g)) {
            g->save[i].bg.rect.left = 400;
            if (g->event.mouseLdown)
                g->save[i].bg.rect.left = 800;
            if (g->event.mouseLup) {
                g->player = g->save[i].data;
            }
        } else {
            g->save[i].bg.rect.left = 0;
        }
        draw_ui(g->save[i].bg, g->view_pos, g->window);
    }
}

void draw_text_preview(global_t *g)
{
    static int init = 0;
    static text_info_t text;

    if (!init++)
        text = init_text_sys(50, "Player", (v2f) {950, 900});
    text.data = my_strdup(g->player.e.name);
    text.pos.x = -2000;
    draw_text_ui(text, g->view_pos, g->window);
    text.pos.x = 950 - sfText_getLocalBounds(text.text).width / 2;
    draw_text_ui(text, g->view_pos, g->window);
}

void draw_preview(global_t *g)
{
    static int init = 0;
    static gameobject_t preview;

    if (!init++) {
        preview = init_sprite("res/play_1.png", 50, 50, (v2f) {700, 380});
        preview.scale = (v2f) {10, 10};
        preview.rect.left = 50;
    }
    if (g->player.race == 0)
        preview.texture = sfTexture_createFromFile("res/play_1.png", NULL);
    if (g->player.race == 1)
        preview.texture = sfTexture_createFromFile("res/play_2.png", NULL);
    draw_ui(preview, g->view_pos, g->window);
}

void update_save_back(global_t *g)
{
    static int init = 0;
    static gameobject_t bg;

    if (!init++)
        bg = init_sprite("res/save_back.png", 450, 900, (v2f) {1450, 25});
    draw_ui(bg, g->view_pos, g->window);
    update_save_selection(g);
    draw_preview(g);
    draw_text_preview(g);
    draw_save(g);
}
