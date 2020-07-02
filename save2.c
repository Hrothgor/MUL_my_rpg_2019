/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void change_name(global_t *g, char *name)
{
    static int ind = 0;

    for (int i = 0; i < sfKeyCount; i++) {
        if (i == sfKeyBack && g->event.key[i] == 1) {
            name[ind-1] = '\0';
            ind--;
            if (ind < 0)
                ind = 0;
        }
        if (i >= sfKeyA && i <= sfKeyZ && g->event.key[i] == 1 && ind <= 15) {
            if (sfKeyboard_isKeyPressed(sfKeyLShift) \
            || sfKeyboard_isKeyPressed(sfKeyRShift))
                name[ind] = i + 'A';
            else
                name[ind] = i + 'a';
            ind++;
        }
    }
}

void enter_name(global_t *g)
{
    static int init = 0;
    static gameobject_t bg;
    static text_info_t text;
    static text_info_t text2;
    static char *name;

    if (!init++) {
        bg = init_sprite("res/name_box.png", 400, 50, (v2f) {725, 960});
        name = malloc(sizeof(char) * 64);
        my_memset(name, 0, 64);
        text = init_text_sys(32, name, (v2f) {765, 965});
        text2 = init_text_sys(32, "Enter Name :", (v2f) {500, 965});
        text.color = sfWhite;
    }
    change_name(g, name);
    draw_ui(bg, g->view_pos, g->window);
    g->player.e.name = my_strdup(name);
    text.data = name;
    draw_text_ui(text, g->view_pos, g->window);
    draw_text_ui(text2, g->view_pos, g->window);
}