/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void update_level_player(global_t *g)
{
    g->player.e.level = 1;
    for (int i = 30; i < 34; i++)
        if (g->player.inventory[i].item.init)
            g->player.e.level += g->player.inventory[i].level;
    g->player.e.maxmana = 100 + (10 * g->player.e.level);
    g->player.e.maxhp = 100 + (20 * g->player.e.level);
}

void update_spell_player(global_t *g)
{
    sfTime time;

    for (int i = 0; i < NB_SPELL; i++) {
        time = sfClock_getElapsedTime(g->spell[i].clock);
        g->spell[i].second = time.microseconds / 1000000.0;
        if (g->spell[i].second >= g->spell[i].cooldown \
        && sfKeyboard_isKeyPressed(g->spell[i].key))  {
            if (g->player.e.mana - g->spell[i].mana >= 0) {
                g->spell[i].UI.func(g, i);
                g->player.e.mana -= g->spell[i].mana;
                sfClock_restart(g->spell[i].clock);
            } else {
                message_middle(g, "Not enough mana");
            }
        }
        g->spell[i].UI.update(g, i);
    }
}

void player_death2(global_t *g)
{
    g->player.e.hp = g->player.e.maxhp;
    g->player.e.mana = g->player.e.maxmana;
    g->player.e.data.pos = (v2f) {9320, 1240};
    message_middle(g, "You died. You lost items.");
    for (int i = 0; i < 65; i++)
        g->ennemi[i].e.hp = g->ennemi[i].e.maxhp;
}

void player_death(global_t *g)
{
    int check = 0;
    int stop = 0;
    int randomitem = 0;

    player_death2(g);
    for (int i = 0; i < 3; i++) {
        check = 0;
        while (check == 0) {
            randomitem = rand() % 34;
            if (g->player.inventory[randomitem].item.init == 1) {
                g->player.inventory[randomitem].item.init = 0;
                check = 1;
            }
            if (stop++ == 500)
                return;
        }
    }
}