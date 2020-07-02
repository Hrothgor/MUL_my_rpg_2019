/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

text_info_t init_text_sys(int size, char *data, sfVector2f pos)
{
    text_info_t ret;

    ret.text = sfText_create();
    ret.font = sfFont_createFromFile("res/menu.ttf");
    ret.size = size;
    ret.data = data;
    ret.color.r = 246;
    ret.color.g = 192;
    ret.color.b = 0;
    ret.color.a = 255;
    sfText_setOutlineThickness(ret.text, 4);
    ret.pos = pos;
    return (ret);
}

void update_slider_0(global_t *g)
{
    static int init = 0;
    static gameobject_t slide;
    static gameobject_t slider;
    static text_info_t text;

    if (!init++) {
        slide = init_sprite("res/slide.png", 399, 24, (v2f) {1000, 300});
        slider = init_sprite("res/slider.png", 40, 44, (v2f) {1200, 293});
        text = init_text_sys(30, "Master Volume", (v2f) \
        {slide.pos.x, slide.pos.y - 40});
    }
    if (hover_button_ui(slide, g->window, g) && g->event.mouseLdown)
        slider.pos.x = g->mouse.x - 15;
    g->volume_master = ((slider.pos.x + 20) - 1000) * 100 / 399;
    draw_ui(slide, g->view_pos, g->window);
    draw_ui(slider, g->view_pos, g->window);
    draw_text_ui(text, g->view_pos, g->window);
}

void update_slider_1(global_t *g)
{
    static int init = 0;
    static gameobject_t slide;
    static gameobject_t slider;
    static text_info_t text;

    if (!init++) {
        slide = init_sprite("res/slide.png", 399, 24, (v2f) {1100, 400});
        slider = init_sprite("res/slider.png", 40, 44, (v2f) {1280, 393});
        text = init_text_sys(30, "Sound", (v2f) \
        {slide.pos.x, slide.pos.y - 40});
    }
    if (hover_button_ui(slide, g->window, g) && g->event.mouseLdown)
        slider.pos.x = g->mouse.x - 15;
    g->volume_sound = ((slider.pos.x + 20) - 1100) * 100 / 399;
    draw_ui(slide, g->view_pos, g->window);
    draw_ui(slider, g->view_pos, g->window);
    draw_text_ui(text, g->view_pos, g->window);
}

void update_slider_2(global_t *g)
{
    static int init = 0;
    static gameobject_t slide;
    static gameobject_t slider;
    static text_info_t text;

    if (!init++) {
        slide = init_sprite("res/slide.png", 399, 24, (v2f) {1100, 500});
        slider = init_sprite("res/slider.png", 40, 44, (v2f) {1280, 493});
        text = init_text_sys(30, "Music", (v2f) \
        {slide.pos.x, slide.pos.y - 40});
    }
    if (hover_button_ui(slide, g->window, g) && g->event.mouseLdown)
        slider.pos.x = g->mouse.x - 20;
    g->volume_music = ((slider.pos.x + 20) - 1100) * 100 / 399;
    draw_ui(slide, g->view_pos, g->window);
    draw_ui(slider, g->view_pos, g->window);
    draw_text_ui(text, g->view_pos, g->window);
}

void update_slider_3(global_t *g)
{
    static int init = 0;
    static gameobject_t slide;
    static gameobject_t slider;
    static text_info_t text;

    if (!init++) {
        slide = init_sprite("res/slide.png", 399, 24, (v2f) {1100, 600});
        slider = init_sprite("res/slider.png", 40, 44, (v2f) {1280, 593});
        text = init_text_sys(30, "Spell", (v2f) \
        {slide.pos.x, slide.pos.y - 40});
    }
    if (hover_button_ui(slide, g->window, g) && g->event.mouseLdown)
        slider.pos.x = g->mouse.x - 15;
    g->volume_spell = ((slider.pos.x + 20) - 1100) * 100 / 399;
    draw_ui(slide, g->view_pos, g->window);
    draw_ui(slider, g->view_pos, g->window);
    draw_text_ui(text, g->view_pos, g->window);
}
