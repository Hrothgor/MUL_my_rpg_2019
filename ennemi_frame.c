/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void ennemi_border(global_t *g, gameobject_t border[2], \
sfRectangleShape *hp, sfRectangleShape *mana)
{
    int len_hp = g->frame.hp * 170 / g->frame.maxhp;
    int len_mana;

    if (g->frame.maxmana != 0)
        len_mana = g->frame.mana * 170 / g->frame.maxmana;
    else
        len_mana = 0;
    sfRectangleShape_setSize(hp, (sfVector2f) {len_hp, 10});
    sfRectangleShape_setSize(mana, (sfVector2f) {len_mana, 10});
    sfRectangleShape_setPosition(hp, \
    (sfVector2f) {395 + g->view_pos.x, 60 + g->view_pos.y});
    sfRectangleShape_setPosition(mana, \
    (sfVector2f) {395 + g->view_pos.x, 75 + g->view_pos.y});
    sfRenderWindow_drawRectangleShape(g->window, hp, NULL);
    sfRenderWindow_drawRectangleShape(g->window, mana, NULL);
}

void update_frame_selection(global_t *g)
{
    if (g->event.mouseLdown)
        for (int i = 0; i < 5; i++)
            if (hover_button(g->ennemi[i].e.data, g->window, g))
                g->frame_update = &g->ennemi[i].e;
    if (g->event.mouseRdown)
        g->frame_update = NULL;
    if (g->frame_update != NULL) {
        g->frame.hp = g->frame_update->hp;
        g->frame.maxhp = g->frame_update->maxhp;
        g->frame.mana = g->frame_update->mana;
        g->frame.maxmana = g->frame_update->maxmana;
        g->frame.name = g->frame_update->name;
        g->frame.icone = g->frame_update->icone;
    }
}
