/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

sfImage *cd_update_text(sfImage *image, float progress, sfColor overlay)
{
    float angle = 0;
    sfVector2u size = sfImage_getSize(image);
    sfVector2f center = (sfVector2f) {size.x/2, size.y/2};
    sfColor pixel;

    for (int y = 0; y < (int) size.y; y++) {
        for (int x = 0; x < (int) size.x; x++) {
            angle = atan2f(y - center.y, x - center.x) * 180 / M_PI + 90;
            if (angle < 0)
                angle += 360;
            pixel = sfImage_getPixel(image, x, y);
            if (angle >= progress*360) {
                pixel.r = (pixel.r + overlay.r) / 2;
                pixel.g = (pixel.g + overlay.g) / 2;
                pixel.b = (pixel.b + overlay.b) / 2;
            }
            sfImage_setPixel(image, x, y, pixel);
        }
    }
    return (image);
}

void print_key_ui(global_t *g, int i)
{
    static int init = 0;
    static text_info_t text;
    sfFloatRect rect;

    if (!init++)
        text = init_text_sys(12, NULL, (v2f) {0, 1000});
    text.data = print_key(g->key.key[i]);
    text.pos.x = -1000;
    draw_text_ui(text, g->view_pos, g->window);
    rect = sfText_getLocalBounds(text.text);
    text.pos.x = 490 + (i-4)*89 - rect.width;
    text.pos.y = 1000;
    draw_text_ui(text, g->view_pos, g->window);
}

void update_spell_ui(global_t *g)
{
    static int init = 0;
    static gameobject_t backui;
    sfImage *copy;

    if (!init++)
        backui = init_sprite("res/back_ui.png", 1300, 155, (v2f) {200, 925});
    draw_ui(backui, g->view_pos, g->window);
    for (int i = 0; i < 10; i++) {
        if (i < NB_SPELL - 4) {
            g->spell[i].progress = g->spell[i].second / g->spell[i].cooldown;
            g->spell[i].UI.pos.x = 410 + 89*i;
            g->spell[i].UI.pos.y = 995;
            g->spell[i].key = g->key.key[i+4];
            copy = cd_update_text(\
            sfImage_copy(g->spell[i].UI.image), g->spell[i].progress, sfRed);
            sfTexture_updateFromImage(g->spell[i].UI.texture, copy, 0, 0);
            draw_ui(g->spell[i].UI, g->view_pos, g->window);
        }
        print_key_ui(g, i+4);
    }
}
