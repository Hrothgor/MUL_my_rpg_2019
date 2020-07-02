/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void button_create(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/button.ogg");
    play_sound(sound, g, 0);
    g->player = init_player(g);
    g->scene = 5;
}

void button_alliance(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/button.ogg");
    play_sound(sound, g, 0);
    g->player.race = 0;
}

void button_horde(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/button.ogg");
    play_sound(sound, g, 0);
    g->player.race = 1;
}

void button_accept_create(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/button.ogg");
    play_sound(sound, g, 0);
    if (g->player.e.name[0] == '\0')
        g->player.e.name = my_strdup("Player");
    print_new_save(g);
    g->save = init_save("save", g);
    g->player = g->save[0].data;
    g->scene = 4;
}

void button_display_map(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/map.ogg");
    play_sound(sound, g, 0);
    g->ui_map = (g->ui_map + 1) % 2;
}