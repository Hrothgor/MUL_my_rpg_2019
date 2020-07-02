/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

spell_t init_ring2(spell_t s)
{
    s.shoot[0].particles = malloc(sizeof(gameobject_t) * 40);
    s.shoot[0].particles[0] = init_sprite("res/ring.png", 512, 512, \
    (v2f) {0, 0});
    for (int i = 1; i < 40; i++)
        s.shoot[0].particles[i] = init_sprite("res/particles_0.png", 64, 64, \
        (v2f) {0, 0});
    return (s);
}

spell_t init_ring(void)
{
    spell_t s;

    s.clock = sfClock_create();
    s.second = 0;
    s.progress = 0;
    s.cooldown = 2;
    s.key = 1;
    s.mana = 0;
    s.sound = create_sound("res/ring");
    s.UI = init_sprite("res/spell_frostbolt.png", 80, 80, (v2f) {1100, 800});
    s.UI.image = sfImage_createFromFile("res/spell_frostbolt.png");
    s.UI.func = ring_func;
    s.UI.update = ring_update;
    s.shoot = malloc(sizeof(gameobject_t));
    s = init_ring2(s);
    return (s);
}
