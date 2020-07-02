/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

spell_t init_aoe2(spell_t s)
{
    s.shoot[0].particles = malloc(sizeof(gameobject_t) * 45);
    s.shoot[0].particles[0] = init_sprite("res/aoe.png", 512, 512, \
    (v2f) {0, 0});
    for (int i = 1; i < 45; i++)
        s.shoot[0].particles[i] = init_sprite("res/aoepart.png", 64, 64, \
        (v2f) {0, 0});
    return (s);
}

spell_t init_aoe(void)
{
    spell_t s;

    s.clock = sfClock_create();
    s.second = 0;
    s.progress = 0;
    s.cooldown = 2;
    s.key = 1;
    s.mana = 20;
    s.sound = create_sound("res/aoe");
    s.UI = init_sprite("res/spell_aoe.png", 80, 80, (v2f) {1100, 800});
    s.UI.image = sfImage_createFromFile("res/spell_aoe.png");
    s.UI.func = aoe_func;
    s.UI.update = aoe_update;
    s.shoot = malloc(sizeof(gameobject_t) * 1);
    s = init_aoe2(s);
    return (s);
}
