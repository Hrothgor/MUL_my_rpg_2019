/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void move_boss(global_t *g, int i)
{
    float size = (float) (sfTexture_getSize(g->boss[i].e.data.texture).x / 2.0);
    float py = (float) (g->player.e.data.pos.y + 25);
    float ey = (float) g->boss[i].e.data.pos.y;
    float px = (float) (g->player.e.data.pos.x + 25);
    float ex = (float) g->boss[i].e.data.pos.x;
    float angle = atan2(py - (ey + size), (px) - (ex + size));

    if ((fabs(sqrt(pow(px - (ex + size), 2) + pow(py - (ey + size), 2))) > \
    g->boss[i].agro && (g->boss[i].phase == 1 || g->boss[i].phase == 3))) {
        g->boss[i].e.data.pos.x += cosf(angle) * g->boss[i].speed;
        g->boss[i].e.data.pos.y += sinf(angle) * g->boss[i].speed;
        boss_animation(g, angle);
    }
}

void boss_death(global_t *g, int i)
{
    if (g->boss[i].e.hp <= 0) {
        g->player.e.data.pos = (v2f) {9320, 1240};
        g->boss[i].e.data.init = 0;
        g->player.end = 1;
        g->player.nb_quest = 6;
        print_new_save(g);
        g->scene = 7;
    }
}

void update_boss_phase(global_t *g, int i)
{
    if (g->boss[i].e.hp < 4000 && g->boss[i].e.hp > 3000)
        g->boss[i].phase = 1;
    if (g->boss[i].e.hp < 3000 && g->boss[i].phase == 1) {
        for (int j = 60; j < 65; j++) {
            g->ennemi[j].ID = j;
            g = init_ennemi2(g, j);
            g = init_mage(g, j);
            update_boss_phase2(g, i, j);
        }
        g->boss[i].phase = 2;
    }
    g->boss[i].phase = g->boss[i].e.hp < 2000 ? 3 : g->boss[i].phase;
}

void update_boss2(global_t *g)
{
    update_boss_phase(g, 0);
    if (g->boss[0].e.hp == 4000)
        g->boss[0].phase = 0;
    if (g->boss[0].e.hp < 1000)
        g->boss[0].phase = 4;
    draw_boss(g, 0);
    move_boss(g, 0);
    if (g->boss[0].phase == 1)
        boss_phase1(g, 0);
    if (g->boss[0].phase == 2)
        boss_phase2(g, 0);
    if (g->boss[0].phase == 3) {
        boss_phase3(g, 0);
        g->boss[0].speed = 7;
    }
    if (g->boss[0].phase == 4)
        boss_phase4(g, 0);
    boss_death(g, 0);
}

void update_boss(global_t *g)
{
    if (g->player.map == 1)
        g->boss[0].e.data.init = 0;
    if (!g->boss[0].e.data.init)
        return;
    update_boss2(g);
}
