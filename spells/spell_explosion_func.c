/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void explosion_func4(void *tmp, int n)
{
    global_t *g = tmp;

    for (int i = 35; i < 55; i++) {
        g->spell[n].shoot[0].particles[i].pos.x = rand() % (int) \
        ((g->mouse.x + 256 + g->view_pos.x) - (g->mouse.x - 256 + \
        g->view_pos.x)) + (g->mouse.x - 256 + g->view_pos.x);
        g->spell[n].shoot[0].particles[i].pos.y = rand() % (int) \
        ((g->mouse.y + 256 + g->view_pos.y) - (g->mouse.y - 256 + \
        g->view_pos.y)) + (g->mouse.y - 256 + g->view_pos.y);
        g->spell[n].shoot[0].particles[i].scale.x = float_rand(1/4, 4/4);
        g->spell[n].shoot[0].particles[i].scale.y = \
        g->spell[n].shoot[0].particles[i].scale.x;
        g->spell[n].shoot[0].particles[i].color.a = 255;
        g->spell[n].shoot[0].particles[i].direction.y = float_rand(1/4, 4/4);
    }
}

void explosion_func3(void *tmp, int n)
{
    global_t *g = tmp;

    for (int i = 20; i < 35; i++) {
        g->spell[n].shoot[0].particles[i].pos.x = (float) \
        (g->mouse.x + g->view_pos.x);
        g->spell[n].shoot[0].particles[i].pos.y = (float) \
        (g->mouse.y + g->view_pos.y);
        g->spell[n].shoot[0].particles[i].scale.x = 2.0;
        g->spell[n].shoot[0].particles[i].scale.y = 2.0;
        g->spell[n].shoot[0].particles[i].color.a = 248;
    }
    g->spell[n].shoot[0].particles[34].color.a = 250;
}

void explosion_func2(void *tmp, int n)
{
    global_t *g = tmp;

    play_sound(g->spell[n].sound, g, 2);
    g->spell[n].state = 1;
    for (int i = 0; i < 5; i++) {
        g->spell[n].shoot[0].particles[i].pos.x = (float) \
        (g->mouse.x + g->view_pos.x);
        g->spell[n].shoot[0].particles[i].pos.y = (float) \
        (g->mouse.y + g->view_pos.y);
        g->spell[n].shoot[0].particles[i].color.a = 0;
    }
    g->spell[n].shoot[0].particles[2].scale.x = 1.0;
    g->spell[n].shoot[0].particles[2].scale.y = 1.0;
    g->spell[n].shoot[0].particles[1].scale.x = 3.0;
    g->spell[n].shoot[0].particles[1].scale.y = 3.0;
    for (int i = 3; i < 5; i++) {
        g->spell[n].shoot[0].particles[i].color.a = 100;
        g->spell[n].shoot[0].particles[i].scale.x = 1.1;
        g->spell[n].shoot[0].particles[i].scale.y = 1.1;
    }
}

void explosion_func(void *tmp, int n)
{
    global_t *g = tmp;

    explosion_func2(tmp, n);
    explosion_func3(tmp, n);
    explosion_func4(tmp, n);
    for (int i = 55; i < 100; i++) {
        g->spell[n].shoot[0].particles[i].pos.x = (float) \
        (g->mouse.x + g->view_pos.x);
        g->spell[n].shoot[0].particles[i].pos.y = (float) \
        (g->mouse.y + g->view_pos.y);
        g->spell[n].shoot[0].particles[i].scale.x = float_rand(1/4, 4/4);
        g->spell[n].shoot[0].particles[i].scale.y = \
        g->spell[n].shoot[0].particles[i].scale.x;
        g->spell[n].shoot[0].particles[i].color.a = 254;
        g->spell[n].shoot[0].particles[i].direction.y = float_rand(1/4, 4/4);
        g->spell[n].shoot[0].particles[i].angle = rand() % 360;
    }
}
