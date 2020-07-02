/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void button_sound_up(void *tmp, int i)
{
    global_t *g = tmp;
    float volume = sfSound_getVolume(g->song) + 10;

    if (volume > 100)
        volume = 100;
    sfSound_setVolume(g->song, volume);
}

void button_sound_down(void *tmp, int i)
{
    global_t *g = tmp;
    float volume = sfSound_getVolume(g->song) - 10;

    if (volume < 0)
        volume = 0;
    sfSound_setVolume(g->song, volume);
}

void button_useless(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/button.ogg");
    play_sound(sound, g, 0);
}
