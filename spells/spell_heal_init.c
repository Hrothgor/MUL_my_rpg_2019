/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

spell_t init_heal2(spell_t s)
{
    s.shoot[0].particles = malloc(sizeof(gameobject_t) * 20);
    for (int i = 0; i < 20; i++) {
        s.shoot[0].particles[i] = init_sprite("res/aoepart.png", 64, 64, \
        (v2f) {0, 0});
        s.shoot[0].particles[i].color.a = 0;
    }
    return (s);
}

spell_t init_heal(void)
{
    spell_t s;

    s.clock = sfClock_create();
    s.second = 0;
    s.progress = 0;
    s.cooldown = 8;
    s.key = 1;
    s.mana = 40;
    s.sound = create_sound("res/heal");
    s.UI = init_sprite("res/spell_heal.png", 80, 80, (v2f) {1100, 800});
    s.UI.image = sfImage_createFromFile("res/spell_heal.png");
    s.UI.func = heal_func;
    s.UI.update = heal_update;
    s.shoot = malloc(sizeof(gameobject_t) * 1);
    s = init_heal2(s);
    return (s);
}
