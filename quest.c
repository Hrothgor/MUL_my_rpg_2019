/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void draw_quest(text_info_t header, text_info_t text, global_t *g, int i)
{
    static int y = 200;

    header.data = g->quest[i].name;
    draw_text_in_box(header, g, &y);
    y += 30;
    text.data = g->quest[i].txt1;
    draw_text_in_box(text, g, &y);
    y += 30;
    header.data = my_strdup("Description");
    draw_text_in_box(header, g, &y);
    y += 30;
    text.data = g->quest[i].txt2;
    draw_text_in_box(text, g, &y);
    y = 200;
    free(header.data);
}

void update_quest_choosen(global_t *g)
{
    if (g->player.nb_quest == 2 && g->player.e.level >= 8) {
        message_middle(g, "Quest finished. New quest added.");
        g->player.nb_quest++;
    }
    if (g->player.nb_quest == 3 && g->player.e.level >= 20) {
        message_middle(g, "Quest finished. New quest added.");
        g->player.nb_quest++;
    }
    if (g->player.nb_quest == 4 && g->player.e.level >= 30) {
        message_middle(g, "Quest finished. New quest added.");
        g->player.nb_quest++;
    }
}

void manage_quest(global_t *g)
{
    static int init = 0;
    static text_info_t text;
    static text_info_t header;
    static text_info_t top_name;

    if (!init++) {
        text = init_text_quest(15, (sfVector2f) {150, 0});
        header = init_header_quest(22, (sfVector2f) {150, 0});
        top_name = init_top_name_quest(15, (sfVector2f) {250, 120});
    }
    draw_ui(g->quest[g->player.nb_quest - 1].bg, g->view_pos, g->window);
    draw_ui(g->quest[g->player.nb_quest - 1].icone, g->view_pos, g->window);
    top_name.data = g->quest[g->player.nb_quest - 1].npc;
    draw_text_ui(top_name, g->view_pos, g->window);
    draw_quest(header, text, g, g->player.nb_quest - 1);
}

void update_quest_interface_ui(global_t *g)
{
    static int init = 0;
    static gameobject_t bg;

    if (!init++)
        bg = init_sprite("res/no_quest.png", 450, 550, (v2f) {100, 100});
    update_quest_choosen(g);
    if (g->ui_quest == 1) {
        if (g->player.nb_quest == 0 || g->player.nb_quest == 6)
            draw_ui(bg, g->view_pos, g->window);
        else
            manage_quest(g);
    }
}
