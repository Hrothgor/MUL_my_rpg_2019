/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

int collide_ennemi(global_t *g, int i)
{
    int posx = g->ennemi[i].e.data.pos.x;
    int posy = g->ennemi[i].e.data.pos.y;

    if (g->player.map == 2)
        return (0);
    if (map[(int) ((posy) / 24)][(int) ((posx) / 24)] == 0)
        return (1);
    if (map[(int) ((posy) / 24)][(int) ((posx + 50) / 24)] == 0)
        return (1);
    if (map[(int) ((posy + 50) / 24)][(int) ((posx + 50) / 24)] == 0)
        return (1);
    if (map[(int) ((posy + 50) / 24)][(int) ((posx) / 24)] == 0)
        return (1);
    return (0);
}

void ennemi_animation(global_t *g, int i, float angle)
{
    sfTime time;
    float second = 0;
    float trigo = sqrtf(2) / 2;

    time = sfClock_getElapsedTime(g->ennemi[i].animation);
    second = time.microseconds / 1000000.0;
    if (cosf(angle) > trigo)
        g->ennemi[i].e.data.rect.top = 100;
    if (cosf(angle) < -trigo)
        g->ennemi[i].e.data.rect.top = 50;
    if (cosf(angle) > -trigo && cosf(angle) < trigo && sinf(angle) < 0)
        g->ennemi[i].e.data.rect.top = 150;
    if (cosf(angle) > -trigo && cosf(angle) < trigo && sinf(angle) > 0)
        g->ennemi[i].e.data.rect.top = 0;
    if (second > 0.2) {
        move_rect(&g->ennemi[i].e.data.rect, 50, 0, 150);
        sfClock_restart(g->ennemi[i].animation);
    }
}

void move_ennemi(global_t *g, int i)
{
    float size = (float) (g->ennemi[i].e.data.rect.width / 2.0);
    float py = (float) (g->player.e.data.pos.y + 25);
    float ey = (float) g->ennemi[i].e.data.pos.y;
    float px = (float) (g->player.e.data.pos.x + 25);
    float ex = (float) g->ennemi[i].e.data.pos.x;
    float angle = atan2(py - (ey + size), (px) - (ex + size));

    if ((fabs(sqrt(pow(px - (ex + size), 2) + pow(py - (ey + size), 2))) < \
    g->ennemi[i].agro && fabs(sqrt(pow(px - (ex + size), 2) + pow(py - (ey + \
    size), 2))) > g->ennemi[i].range && g->ennemi[i].status == 1) || \
    ((g->ennemi[i].e.hp != g->ennemi[i].e.maxhp) && fabs(sqrt(pow(px - (ex + \
    size), 2) + pow(py - (ey + size), 2))) > g->ennemi[i].range)) {
        g->ennemi[i].e.data.pos.x += cosf(angle) * g->ennemi[i].speed;
        g->ennemi[i].e.data.pos.y += sinf(angle) * g->ennemi[i].speed;
        ennemi_animation(g, i, angle);
        if (collide_ennemi(g, i)) {
            g->ennemi[i].e.data.pos.x -= cosf(angle) * g->ennemi[i].speed;
            g->ennemi[i].e.data.pos.y -= sinf(angle) * g->ennemi[i].speed;
        }
    }
}

void ennemi_attack(global_t *g, int i)
{
    sfTime time;

    time = sfClock_getElapsedTime(g->ennemi[i].clock);
    g->ennemi[i].second = time.microseconds / 1000000.0;
    if (fabs(sqrt(pow((g->player.e.data.pos.x + 25) - \
    (g->ennemi[i].e.data.pos.x + \
    (g->ennemi[i].e.data.rect.width / 2.0)), 2) + \
    pow((g->player.e.data.pos.y + 25) - (g->ennemi[i].e.data.pos.y + \
    (g->ennemi[i].e.data.rect.width / 2.0)), 2))) <= \
    g->ennemi[i].range && g->ennemi[i].second >= g->ennemi[i].dps) {
        sfClock_restart(g->ennemi[i].clock);
        if (!g->ennemi[i].ranged)
            g->player.e.hp -= g->ennemi[i].dmg;
        else
            fireball_func(g, i);
    }
}

void update_ennemi(global_t *g)
{

    for (int i = 0; i < 60; i++) {
        if (!g->ennemi[i].e.data.init) {
            respawn_ennemi(g, i);
            continue;
        }
        draw_ennemi(g, i);
        ennemi_attack(g, i);
        move_ennemi(g, i);
        ennemi_death(g, i);
    }
}
