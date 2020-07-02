/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

text_info_t init_text_middle(int size)
{
    text_info_t ret;

    ret.text = sfText_create();
    ret.font = sfFont_createFromFile("res/menu.ttf");
    ret.size = size;
    ret.data = NULL;
    ret.color.r = 245;
    ret.color.g = 2;
    ret.color.b = 2;
    ret.color.a = 0;
    sfText_setStyle(ret.text, sfTextBold);
    ret.pos = (v2f) {960, 250};
    return (ret);
}

void message_middle(global_t *g, char *message)
{
    sfFloatRect rect;

    g->text_middle.color.a = 255;
    g->text_middle.data = my_strdup(message);
    g->text_middle.pos.x = -2000;
    draw_text_ui(g->text_middle, g->view_pos, g->window);
    rect = sfText_getLocalBounds(g->text_middle.text);
    g->text_middle.pos.x = 960 - rect.width / 2;
}

void text_middle(global_t *g)
{
    if (g->text_middle.data != NULL)
        draw_text_ui(g->text_middle, g->view_pos, g->window);
    if (g->text_middle.color.a > 0)
        g->text_middle.color.a -= 1;
    else
        g->text_middle.color.a = 0;
}