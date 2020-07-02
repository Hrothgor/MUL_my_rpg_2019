/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void fireball_func2(void *tmp, int n)
{
    global_t *g = tmp;
    static int sound = 0;

    if (sound == 0)
        play_sound(g->spell[n].sound, g, 2);
    if (sound == 1)
        play_sound(g->spell[n].sound2, g, 2);
    if (sound == 2)
        play_sound(g->spell[n].sound3, g, 2);
    sound++;
    if (sound == 3)
        sound = 0;
}