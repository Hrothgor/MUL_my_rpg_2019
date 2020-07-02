/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

player_t init_player2(player_t ret, global_t *g)
{
    ret.inventory = malloc(sizeof(item_t) * 34);
    for (int i = 0; i < 34; i++) {
        ret.inventory[i].item.init = 0;
        ret.inventory[i].item.rect.height = 80;
        ret.inventory[i].item.rect.width = 80;
    }
    ret.race = 0;
    ret.gold = 0;
    ret.nb_quest = 0;
    return (ret);
}

player_t init_player(global_t *g)
{
    player_t ret;

    ret.e.data = init_sprite("res/play_1.png", 50, 50, (v2f) {960, 540});
    ret.e.data.speed = 10;
    ret.shield = 0;
    ret.e.level = 1;
    ret.e.data.direction = (v2f) {0, 0};
    ret.begin_pos = ret.e.data.pos;
    ret.end_pos = ret.e.data.pos;
    ret.e.hp = 100 * (ret.e.level * 1.2);
    ret.e.mana = 100 * (ret.e.level * 1.2);
    ret.e.maxhp = ret.e.hp;
    ret.e.maxmana = ret.e.mana;
    ret.end = 0;
    ret.clock = sfClock_create();
    return (init_player2(ret, g));
}

void init_spell(global_t *g)
{
    g->spell = malloc(sizeof(spell_t) * NB_SPELL);
    g->spell[0] = init_frostbolt();
    g->spell[1] = init_blink();
    g->spell[2] = init_shield();
    g->spell[3] = init_explosion();
    g->spell[4] = init_aoe();
    g->spell[5] = init_heal();
    g->spell[6] = init_fireball();
    g->spell[7] = init_sickle();
    g->spell[8] = init_ring();
    g->spell[9] = init_zone();
}
