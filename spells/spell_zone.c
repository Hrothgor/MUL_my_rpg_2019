/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void update_zone_particles2(global_t *g, gameobject_t shoot, int i)
{
    if (shoot.particles[i].color.a > 2)
        shoot.particles[i].color.a -= 2;
    if (shoot.particles[i].color.a <= 2)
        shoot.particles[i].init = 0;
}

void update_zone_particles(global_t *g, gameobject_t shoot)
{
    for (int i = 0; i < 40; i++) {
        if (shoot.particles[i].init) {
            shoot.particles[i].pos.x += cosf(shoot.particles[i].angle) * \
            5 * shoot.particles[i].scale.x;
            shoot.particles[i].pos.y += sinf(shoot.particles[i].angle) * 5 \
            * shoot.particles[i].scale.y;
            shoot.particles[i].scale.x -= 0.02f;
            shoot.particles[i].scale.y -= 0.02f;
            update_zone_particles2(g, shoot, i);
            draw_mode(shoot.particles[i], \
            blend_moden(shoot.particles[i].texture), g->window);
        }
    }
}

void zone_particles(global_t *g, gameobject_t shoot)
{
    static float scale = 0;

    for (int i = 0; i < 40; i++) {
        if (!shoot.particles[i].init) {
            shoot.particles[i].init = 1;
            shoot.particles[i].pos = (v2f) {shoot.pos.x - shoot.direction.x, \
            shoot.pos.y - shoot.direction.y};
            scale = float_rand(1/4, 4/4);
            shoot.particles[i].scale = (v2f) {scale, scale};
            shoot.particles[i].angle = rand() % 360;
            break;
        }
    }
    update_zone_particles(g, shoot);
}

void zone_dammage(global_t *g, int n, int i)
{
    if ((fabs(sqrt(pow((g->spell[n].shoot[i].pos.x) - \
    (g->player.e.data.pos.x + 25), 2) + \
    pow((g->spell[n].shoot[i].pos.y) - (g->player.e.data.pos.y + 25), \
    2))) < 256) && g->spell[n].shoot[i].init) {
        if (g->player.shield) {
            g->player.shield = 0;
        } else {
            g->player.e.hp -= 1;
        }
    }
}

void zone_update(void *tmp, int n)
{
    global_t *g = tmp;

    for (int i = 0; i < 40; i++) {
        if (g->spell[n].shoot[i].init) {
            g->spell[n].shoot[i].rotation += 5;
            if (g->spell[n].shoot[i].color.a > 2) {
                zone_dammage(g, n, i);
                g->spell[n].shoot[i].color.a -= 2;
            }
            draw_mode(g->spell[n].shoot[i], \
            blend_moden(g->spell[n].shoot[i].texture), g->window);
            zone_particles(g, g->spell[n].shoot[i]);
        }
    }
}
