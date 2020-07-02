/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void animation_player(global_t *g)
{
    sfTime time;

    time = sfClock_getElapsedTime(g->player.clock);
    g->player.second = time.microseconds / 1000000.0;
    if (g->player.e.data.direction.x ||  g->player.e.data.direction.y) {
        if (g->player.second > 0.2) {
            move_rect(&g->player.e.data.rect, 50, 0, 150);
            sfClock_restart(g->player.clock);
        }
    } else
        g->player.e.data.rect.left = 50;
}

void move_player2(global_t *g)
{
    if (sfKeyboard_isKeyPressed(g->key.key[1])) {
        g->player.e.data.direction.y = g->player.e.data.speed;
        g->player.e.data.rect.top = 0;
        if (collide(g) || collide_boss_map(g))
            g->player.e.data.direction.y = 0;
    }
    if (sfKeyboard_isKeyPressed(g->key.key[0])) {
        g->player.e.data.direction.y = -g->player.e.data.speed;
        g->player.e.data.rect.top = 150;
        if (collide(g) || collide_boss_map(g))
            g->player.e.data.direction.y = 0;
    }
    animation_player(g);
}

void move_player(global_t *g)
{
    g->player.e.data.direction = (v2f) {0, 0};
    if (sfKeyboard_isKeyPressed(g->key.key[3])) {
        g->player.e.data.direction.x = g->player.e.data.speed;
        g->player.e.data.rect.top = 100;
        if (collide(g) || collide_boss_map(g))
            g->player.e.data.direction.x = 0;
    }
    if (sfKeyboard_isKeyPressed(g->key.key[2])) {
        g->player.e.data.direction.x = -g->player.e.data.speed;
        g->player.e.data.rect.top = 50;
        if (collide(g) || collide_boss_map(g))
            g->player.e.data.direction.x = 0;
    }
    move_player2(g);
}

void update_player2(global_t *g)
{
    move_player(g);
    g->player.e.data.pos.x += g->player.e.data.direction.x;
    g->player.e.data.pos.y += g->player.e.data.direction.y;
    if (g->player.e.mana < g->player.e.maxmana)
        g->player.e.mana += 0.2 * g->player.e.maxmana / 100;
    if (g->player.e.data.pos.x + 25 < 6984 && g->player.e.data.pos.x + \
    25 > 6848 && g->player.e.data.pos.y + 25 < 7650 && g->player.e.data.pos.y \
    + 25 > 7578) {
        if (item_in_inventory("dungeon_key", g)) {
            g->player.e.data.pos.x = 20720;
            g->player.e.data.pos.y = 21439;
            g->player.map = 2;
            if (g->player.end == 0) {
                g->boss[0].e.data.init = 1;
                g->boss[0].e.hp = g->boss[0].e.maxhp;
                g->boss[0].e.data.pos = (v2f) {20725, 20500};
            }
        } else
            message_middle(g, "You need the key to enter.");
    }
}

void update_player(global_t *g)
{
    if (g->player.e.hp <= 0) {
        for (int i = 60; i < 65; i++)
            g->ennemi[i].e.data.init = 0;
        player_death(g);
    }
    g->player.map = g->player.e.data.pos.x > 10000 ? 2 : 1;
    draw(g->player.e.data, g->window);
    update_level_player(g);
    update_player2(g);
    update_spell_player(g);
    if (g->player.e.mana > g->player.e.maxmana)
        g->player.e.mana = g->player.e.maxmana;
    if (g->player.e.hp > g->player.e.maxhp)
        g->player.e.hp = g->player.e.maxhp;
}
