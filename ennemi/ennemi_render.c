/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void draw_life(ennemi_t g, sfRenderWindow *window, global_t *glo)
{
    g.lb.pos.x = g.e.data.pos.x + \
    (g.e.data.rect.width / 2.0) - 50;
    g.lb.pos.y = g.e.data.pos.y - 15;
    g.l.pos.x = g.e.data.pos.x + \
    (g.e.data.rect.width / 2.0) - 50;
    g.l.pos.y = g.e.data.pos.y - 15;
    g.l.color = sfGreen;
    g.l.scale.x = g.e.hp / g.e.maxhp;
    g.lb.color = sfRed;
    if (hover_button(g.e.data, window, glo) || g.e.hp != g.e.maxhp) {
        draw(g.lb, window);
        draw(g.l, window);
    }
}

void draw_name(ennemi_t g, sfRenderWindow *window)
{
    static int init = 0;
    static sfText *text;
    static sfFont *font;

    if (!init++) {
        text = sfText_create();
        font = sfFont_createFromFile("res/menu.ttf");
        sfText_setFont(text, font);
    }
    sfText_setString (text, g.name);
    sfText_setColor (text, sfWhite);
    sfText_setPosition (text, (v2f) {g.e.data.pos.x + \
    (g.e.data.rect.width / 2.0) - \
    sfText_getGlobalBounds(text).width / 2, g.e.data.pos.y - 50});
    sfRenderWindow_drawText(window, text, NULL);
}

void draw_ennemi(global_t *g, int i)
{
    draw(g->ennemi[i].e.data, g->window);
    if (hover_button(g->ennemi[i].e.data, g->window, g))
        draw_name(g->ennemi[i], g->window);
    draw_life(g->ennemi[i], g->window, g);
}