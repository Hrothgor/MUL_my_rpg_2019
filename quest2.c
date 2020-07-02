/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

text_info_t init_text_quest(int size, sfVector2f pos)
{
    text_info_t ret;

    ret.text = sfText_create();
    ret.font = sfFont_createFromFile("res/menu.ttf");
    ret.size = size;
    ret.color = sfBlack;
    ret.pos = pos;
    return (ret);
}

text_info_t init_header_quest(int size, sfVector2f pos)
{
    text_info_t ret;

    ret.text = sfText_create();
    ret.font = sfFont_createFromFile("res/quest.ttf");
    ret.size = size;
    ret.color = sfBlack;
    ret.pos = pos;
    sfText_setOutlineThickness(ret.text, 0.3);
    return (ret);
}

text_info_t init_top_name_quest(int size, sfVector2f pos)
{
    text_info_t ret;

    ret.text = sfText_create();
    ret.font = sfFont_createFromFile("res/menu.ttf");
    ret.size = size;
    ret.color = sfWhite;
    ret.pos = pos;
    return (ret);
}

int length_of_word(text_info_t text, char *word)
{
    sfFloatRect rect;

    text.data = word;
    rect = sfText_getGlobalBounds(text.text);
    return (rect.width);
}

void draw_text_in_box(text_info_t text, global_t *g, int *y)
{
    char **arr = my_str_to_word_array(text.data);
    int current = 150;
    int size = sfText_getCharacterSize(text.text);
    sfFloatRect rect;

    for (int i = 0; arr[i]; i++) {
        if (length_of_word(text, arr[i]) + current >= 450) {
            current = 150;
            *y += size + 5;
        }
        text.pos.x = current;
        text.pos.y = *y;
        text.data = arr[i][0] == '#' ? my_strdup("Hrothgor") : arr[i];
        draw_text_ui(text, g->view_pos, g->window);
        rect = sfText_getGlobalBounds(text.text);
        text.data = my_strdup(" ");
        draw_text_ui(text, g->view_pos, g->window);
        current += rect.width + size/2;
        free(text.data);
    }
}