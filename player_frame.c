/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void player_border_next(global_t *g)
{
    static int init = 0;
    static text_info_t text;
    sfFloatRect rect;

    if  (!init++)
        text = init_text_sys(15, NULL, (v2f) {0, 0});
    text.data = my_strdup(g->player.e.name);
    text.pos.x = -1000;
    draw_text_ui(text, g->view_pos, g->window);
    rect = sfText_getLocalBounds(text.text);
    text.pos = (v2f) {200 - rect.width / 2, 32};
    draw_text_ui(text, g->view_pos, g->window);
    text.data = my_itostr(g->player.e.level);
    text.pos.x = -1000;
    draw_text_ui(text, g->view_pos, g->window);
    rect = sfText_getLocalBounds(text.text);
    text.pos = (v2f) {32 - rect.width / 2, 82};
    draw_text_ui(text, g->view_pos, g->window);
    free(text.data);
}

void player_border(global_t *g, gameobject_t border[2], \
sfRectangleShape *hp, sfRectangleShape *mana)
{
    int len_hp = g->player.e.hp * 170 / g->player.e.maxhp;
    int len_mana = g->player.e.mana * 170 / g->player.e.maxmana;

    sfRectangleShape_setSize(hp, (sfVector2f) {len_hp, 10});
    sfRectangleShape_setSize(mana, (sfVector2f) {len_mana, 10});
    sfRectangleShape_setPosition(hp, \
    (sfVector2f) {105 + g->view_pos.x, 60 + g->view_pos.y});
    sfRectangleShape_setPosition(mana, \
    (sfVector2f) {105 + g->view_pos.x, 75 + g->view_pos.y});
    sfRenderWindow_drawRectangleShape(g->window, hp, NULL);
    sfRenderWindow_drawRectangleShape(g->window, mana, NULL);
    draw_ui(border[0], g->view_pos, g->window);
    draw_ui(border[1], g->view_pos, g->window);
    player_border_next(g);
}
