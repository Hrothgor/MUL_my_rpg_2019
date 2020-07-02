/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void update_frame(global_t *g)
{
    static int init = 0;
    static gameobject_t b[2];
    static sfRectangleShape *hp;
    static sfRectangleShape *mana;

    if (!init++) {
        b[0] = init_sprite("res/frame_1.png", 270, 100, (sfVector2f) {0, 10});
        b[1] = init_sprite("res/frame_2.png", 38, 38, (sfVector2f) {0, 70});
        hp = create_rectangle(sfGreen);
        mana = create_rectangle(sfBlue);
    }
    update_frame_selection(g);
    b[0].pos.x = 10;
    b[1].pos.x = 10;
    player_border(g, b, hp, mana);
    b[0].pos.x = 300;
    b[1].pos.x = 300;
    if (g->frame_update != NULL)
        ennemi_border(g, b, hp, mana);
}
