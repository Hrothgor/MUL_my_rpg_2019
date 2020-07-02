/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void play_sound(sfSound *sound, global_t *g, int i)
{
    float volume = 0;
    if (i == 0) {
        volume = ((float) g->volume_master / 100) * g->volume_sound * 2;
        sfSound_setVolume(sound, volume);
        sfSound_play(sound);
    }
    if (i == 1) {
        volume = ((float) g->volume_master / 100) * g->volume_music;
        sfSound_setVolume(sound, volume);
        sfSound_play(sound);
    }
    if (i == 2) {
        volume = ((float) g->volume_master / 100) * g->volume_spell;
        sfSound_setVolume(sound, volume);
        sfSound_play(sound);
    }
    if (i == 3) {
        volume = ((float) g->volume_master / 100) * g->volume_music / 2;
        sfSound_setVolume(sound, volume);
    }
}