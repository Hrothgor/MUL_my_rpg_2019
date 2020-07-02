/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void button_save(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/button.ogg");
    play_sound(sound, g, 0);
    print_new_save(g);
    g->save = init_save("save", g);
    message_middle(g, "Game save succeed");
}

void button_pause(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/pause.ogg");
    play_sound(sound, g, 0);
    g->scene = 6;
}

void button_htp(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/button.ogg");
    play_sound(sound, g, 0);
    g->scene = 8;
}