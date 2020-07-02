/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void button_display_quest(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/quest.ogg");
    play_sound(sound, g, 0);
    g->ui_quest = (g->ui_quest + 1) % 2;
}

void button_display_inventory(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/bag.ogg");
    play_sound(sound, g, 0);
    g->ui_inventory = (g->ui_inventory + 1) % 2;
}

void button_menu(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/button.ogg");
    play_sound(sound, g, 0);
    g->scene = 0;
}

void button_start(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/button.ogg");
    play_sound(sound, g, 0);
    g->scene = 1;
}

void button_system_sound(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/button.ogg");
    play_sound(sound, g, 0);
    g->scene = 2;
}