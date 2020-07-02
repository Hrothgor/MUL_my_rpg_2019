/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void button_system_key(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/button.ogg");
    play_sound(sound, g, 0);
    g->scene = 3;
}

void button_connexion(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/button.ogg");
    play_sound(sound, g, 0);
    if (!g->save[0].bg.init)
        g->scene = 5;
    else {
        g->save = init_save("save", g);
        g->player = g->save[0].data;
        g->scene = 4;
    }
}

void button_quitter(void *tmp, int i)
{
    global_t *g = tmp;
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/button.ogg");
    play_sound(sound, g, 0);
    sfRenderWindow_close(g->window);
}

void button_key_slide_down(void *tmp, int i)
{
    global_t *g = tmp;

    g->key.sliding += 200;
    if (g->key.sliding > 650)
        g->key.sliding = 650;
}

void button_key_slide_up(void *tmp, int i)
{
    global_t *g = tmp;

    g->key.sliding -= 200;
    if (g->key.sliding < 0)
        g->key.sliding = 0;
}