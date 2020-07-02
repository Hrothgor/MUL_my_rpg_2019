/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

spell_t init_shield2(spell_t s)
{
    s.clock = sfClock_create();
    s.second = 0;
    s.progress = 0;
    s.cooldown = 30;
    s.key = 0;
    s.mana = 5;
    s.sound = create_sound("res/shield.ogg");
    s.UI = init_sprite("res/spell_shield.png", 80, 80, (v2f) {1000, 800});
    s.UI.image = sfImage_createFromFile("res/spell_shield.png");
    s.UI.func = shield_func;
    s.UI.update = shield_update;
    s.shoot = malloc(sizeof(gameobject_t));
    s.shoot[0].particles = malloc(sizeof(gameobject_t) * 20);
    s.shoot[0].particles[0] = init_sprite("res/shield.png", 128, 128, \
    (v2f) {0, 0});
    s.shoot[0].particles[1] = init_sprite("res/shield.png", 128, 128, \
    (v2f) {0, 0});
    return (s);
}

spell_t init_shield(void)
{
    spell_t s;

    s = init_shield2(s);
    for (int i = 2; i < 7; i++) {
        s.shoot[0].particles[i] = init_sprite("res/dual.png", 128, 64, \
        (v2f) {0, 0});
        s.shoot[0].particles[i].rotation = 30 * i;
    }
    for (int i = 7; i < 20; i++) {
        s.shoot[0].particles[i] = init_sprite("res/shine.png", 32, 32, \
        (v2f) {0, 0});
        s.shoot[0].particles[i].rotation = -5 + (1 * i);
        s.shoot[0].particles[i].color.a -= 15 * i;
    }
    return (s);
}
