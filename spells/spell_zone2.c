/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void init_zone_particles(global_t *g, gameobject_t shoot)
{
    for (int i = 0; i < 40; i++) {
        shoot.particles[i].init = 0;
        shoot.particles[i].scale.y = 1;
        shoot.particles[i].scale.x = 1;
        shoot.particles[i].color.a = 255;
    }
}
