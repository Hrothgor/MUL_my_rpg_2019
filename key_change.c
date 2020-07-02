/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

const char *tabl[24] = {
    "Move Forward",
    "Move Backward",
    "Move Left",
    "Move Right",
    "Bottom Action Button 1",
    "Bottom Action Button 2",
    "Bottom Action Button 3",
    "Bottom Action Button 4",
    "Bottom Action Button 5",
    "Bottom Action Button 6",
    "Bottom Action Button 7",
    "Bottom Action Button 8",
    "Bottom Action Button 9",
    "Bottom Action Button 10",
    "Top Action Button 1",
    "Top Action Button 2",
    "Top Action Button 3",
    "Top Action Button 4",
    "Top Action Button 5",
    "Top Action Button 6",
    "Top Action Button 7",
    "Top Action Button 8",
    "Top Action Button 9",
    "Top Action Button 10"
};

void update_slider_key(global_t *g)
{
    static int init = 0;
    static gameobject_t slide;
    static gameobject_t slider;

    if (!init++) {
        slide = init_sprite("res/slide_key.png", 50, 690, (v2f) {1467, 210});
        slider = init_sprite("res/slider_key.png", 40, 40, (v2f) {1472, 210});
    }
    if (hover_button_ui(slide, g->window, g) && g->event.mouseLdown)
        g->key.sliding = g->mouse.y - 230;
    if (g->key.sliding < 0)
        g->key.sliding = 0;
    if (g->key.sliding > 650)
        g->key.sliding = 650;
    slider.pos.y = 210 + g->key.sliding;
    draw_ui(slide, g->view_pos, g->window);
    draw_ui(slider, g->view_pos, g->window);
}

int event_border(global_t *g, int i)
{
    static int chosen = -1;
    static int init = 0;
    static gameobject_t bord;

    if (!init++)
        bord = init_sprite("res/button_model.png", 250, 40, (v2f) {1100, 0});
    bord.pos.y = 225 + (((i+6)/10)+i)*50 - g->key.sliding;
    if (hover_button_ui(bord, g->window, g)) {
            bord.rect.left = bord.rect.width;
            if (g->event.mouseLdown)
                bord.rect.left = 2 * bord.rect.width;
            if (g->event.mouseLup)
                chosen = i;
    } else if (chosen == i) {
        bord.rect.left = 2 * bord.rect.width;
    } else
        bord.rect.left = 0;
    if (g->event.mouseRup)
        chosen = -1;
    draw_ui(bord, g->view_pos, g->window);
    return (chosen);
}

void print_key_change(global_t *g, text_info_t text, int i)
{
    sfFloatRect rect;

    text.pos.x = -1000;
    draw_text_ui(text, g->view_pos, g->window);
    rect = sfText_getLocalBounds(text.text);
    text.pos.x = 1225 - rect.width / 2;
    draw_text_ui(text, g->view_pos, g->window);
}

void key_change(global_t *g, int i)
{
    static int init = 0;
    static text_info_t text;
    int j = 0;
    int chosen = event_border(g, i);

    if (!init++)
        text = init_text_sys(20, NULL, (v2f) {1100, 0});
    for (; j < sfKeyCount; j++) {
        if (g->event.key[j] == 1 && i == chosen) {
            g->key.key[i] = j;
            break;
        }
    }
    for (int k = 0; k < 24; k++)
        if (g->key.key[k] == j && k != i)
            g->key.key[k] = -1;
    text.pos.y = 225 + (((i+6)/10)+i)*50 - g->key.sliding + 10;
    text.data = g->key.key[i] != -1 ? \
    print_key(g->key.key[i]) : my_strdup("Not Bound");
    print_key_change(g, text, i);
}

void update_key_change(global_t *g)
{
    static int init = 0;
    static text_info_t text;

    if (!init++)
        text = init_text_sys(25, NULL, (v2f) {725, 0});
    for (int i = 0; i < 24; i++) {
        if ((((i+6)/10)+i)*50 - g->key.sliding >= 0 && \
        (((i+6)/10)+i)*50 - g->key.sliding <= 650) {
            text.data = my_strdup(tabl[i]);
            text.pos.y = 225 + (((i+6)/10)+i)*50 - g->key.sliding;
            draw_text_ui(text, g->view_pos, g->window);
            key_change(g, i);
            free(text.data);
        }
    }
}
