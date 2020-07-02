/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void init_pnj(global_t *g)
{
    pnj_t *pnj = malloc(sizeof(pnj_t) * 7);

    for (int i = 0; i < 5; i++)
        pnj[i].e.data.init = 0;
    pnj[0].e.data = init_sprite("res/pnj_1.png", 50, 50, (v2f) {5900, 2010});
    pnj[0].state = 1;
    pnj[1].e.data = init_sprite("res/pnj_1.png", 50, 50, (v2f) {6300, 2420});
    pnj[1].state = 1;
    pnj[2].e.data = init_sprite("res/pnj_1.png", 50, 50, (v2f) {7040, 2200});
    pnj[2].state = 1;
    pnj[3].e.data = init_sprite("res/pnj_2.png", 50, 50, (v2f) {1380, 1880});
    pnj[4].e.data = init_sprite("res/pnj_3.png", 50, 50, (v2f) {6350, 1330});
    pnj[5].e.data = init_sprite("res/guard.png", 50, 50, (v2f) {3500, 3510});
    pnj[6].e.data = init_sprite("res/guard.png", 50, 50, (v2f) {3950, 3510});
    g->pnj = pnj;
}

void update_vendor_click(global_t *g, int i)
{
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/vendor.ogg");
    if (hover_button(g->pnj[i].e.data, g->window, g) && g->event.mouseRup \
    && g->pnj[i].state == 1) {
        if (pythagore(g->player.e.data.pos.x - g->pnj[i].e.data.pos.x, \
        g->player.e.data.pos.y - g->pnj[i].e.data.pos.y) < 150 * 150) {
            g->ui_shop = i+1;
            play_sound(sound, g, 0);
        } else {
            message_middle(g, "I need to get closer");
        }
    }
}

void update_first_pnj_quest(global_t *g)
{
    if (g->player.nb_quest == 0 && (g->player.e.data.pos.y > 2170 || \
    g->player.e.data.pos.x > 3010)) {
        g->player.e.data.pos = (v2f) {1590, 2010};
        message_middle(g, "Talk to Raleigh before leaving this area.");
    }
    if (hover_button(g->pnj[3].e.data, g->window, g) && g->event.mouseRup) {
        if (pythagore(g->player.e.data.pos.x - g->pnj[3].e.data.pos.x, \
        g->player.e.data.pos.y - g->pnj[3].e.data.pos.y) < 150 * 150) {
            if (g->player.nb_quest == 0) {
                g->player.nb_quest = 1;
                message_middle(g, "New quest added, open your quest log.");
            } else {
                message_middle(g, "It has nothing to say.");
            }
        } else {
            message_middle(g, "I need to get closer");
        }
    }
    draw(g->pnj[3].e.data, g->window);
}

void update_second_pnj_quest(global_t *g)
{
    if (hover_button(g->pnj[4].e.data, g->window, g) && g->event.mouseRup) {
        if (pythagore(g->player.e.data.pos.x - g->pnj[4].e.data.pos.x, \
        g->player.e.data.pos.y - g->pnj[4].e.data.pos.y) < 150 * 150) {
            if (g->player.nb_quest == 1) {
                g->player.nb_quest = 2;
                message_middle(g, "New quest added, open your quest log.");
            } else {
                message_middle(g, "It has nothing to say.");
            }
        } else {
            message_middle(g, "I need to get closer");
        }
    }
    draw(g->pnj[4].e.data, g->window);
}

void update_pnj(global_t *g)
{
    for (int i = 0; i < 3; i++) {
        update_vendor_click(g, i);
        draw(g->pnj[i].e.data, g->window);
    }
    update_first_pnj_quest(g);
    update_second_pnj_quest(g);
    draw(g->pnj[5].e.data, g->window);
    draw(g->pnj[6].e.data, g->window);
}