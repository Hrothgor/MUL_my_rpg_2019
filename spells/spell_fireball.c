/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void update_fireball_particles2(global_t *g, gameobject_t shoot, int i)
{
    if (shoot.particles[i].color.a > 0)
        shoot.particles[i].color.a -= 5;
    if (shoot.particles[i].color.a <= 0)
        shoot.particles[i].init = 0;
}

void update_fireball_particles(global_t *g, gameobject_t shoot)
{
    for (int i = 0; i < 40; i++) {
        if (shoot.particles[i].init) {
            shoot.particles[i].pos.x += cosf(shoot.particles[i].angle) * \
            5 * shoot.particles[i].scale.x;
            shoot.particles[i].pos.y += sinf(shoot.particles[i].angle) * 5 \
            * shoot.particles[i].scale.y;
            shoot.particles[i].scale.x -= 0.02f;
            shoot.particles[i].scale.y -= 0.02f;
            update_fireball_particles2(g, shoot, i);
            draw_mode(shoot.particles[i], \
            blend_moden(shoot.particles[i].texture), g->window);
        }
    }
}

void fireball_particles(global_t *g, gameobject_t shoot)
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
    update_fireball_particles(g, shoot);
}

void fireball_dammage(global_t *g, int n, int i)
{
    if ((fabs(sqrt(pow((g->spell[n].shoot[i].pos.x) - \
    (g->player.e.data.pos.x + 25), 2) + \
    pow((g->spell[n].shoot[i].pos.y) - (g->player.e.data.pos.y + 25), \
    2))) < 100) && g->spell[n].shoot[i].init) {
        if (g->player.shield) {
            g->player.shield = 0;
        } else {
            g->player.e.hp -= 50;
            g->spell[n].shoot[i].init = 0;
        }
    }
}

void fireball_update(void *tmp, int n)
{
    global_t *g = tmp;

    for (int i = 0; i < 40; i++) {
        if (g->spell[n].shoot[i].pos.x < (-1000 + g->view_pos.x) \
        || g->spell[n].shoot[i].pos.x > (2920 + g->view_pos.x) || \
        g->spell[n].shoot[i].pos.y < (-1000 + g->view_pos.y) || \
        g->spell[n].shoot[i].pos.y > (2080 + g->view_pos.y))
            g->spell[n].shoot[i].init = 0;
        if (g->spell[n].shoot[i].init) {
            g->spell[n].shoot[i].rotation += 10;
            g->spell[n].shoot[i].pos.x += g->spell[n].shoot[i].direction.x;
            g->spell[n].shoot[i].pos.y += g->spell[n].shoot[i].direction.y;
            draw_mode(g->spell[n].shoot[i], \
            blend_moden(g->spell[n].shoot[i].texture), g->window);
            fireball_particles(g, g->spell[n].shoot[i]);
            fireball_dammage(g, n, i);
        }
    }
}
