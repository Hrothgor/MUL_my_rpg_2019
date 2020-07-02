/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

spell_t init_explosion4(spell_t s)
{
    for (int i = 25; i < 30; i++) {
        s.shoot[0].particles[i] = init_sprite("res/blast1.png", 128, 128, \
        (v2f) {0, 0});
        s.shoot[0].particles[i].rotation = -60 + 30 * (i - 25);
    }
    for (int i = 30; i < 34; i++) {
        s.shoot[0].particles[i] = init_sprite("res/blast2.png", 256, 256, \
        (v2f) {0, 0});
        s.shoot[0].particles[i].rotation = -60 + 30 * (i - 30);
    }
        s.shoot[0].particles[34] = init_sprite("res/flare.png", 256, 142, \
        (v2f) {0, 0});
    for (int i = 35; i < 45; i++) {
        s.shoot[0].particles[i] = init_sprite("res/depo0.png", 32, 32, \
        (v2f) {0, 0});
        s.shoot[0].particles[i].rotation = -60 + 30 * (i - 35);
    }
    return (s);
}

spell_t init_explosion3(spell_t s)
{
    s.shoot[0].particles[2] = init_sprite("res/flare.png", 256, 142, (v2f) \
    {0, 0});
    s.shoot[0].particles[3] = init_sprite("res/glyph2.png", 256, 256, (v2f) \
    {0, 0});
    s.shoot[0].particles[4] = init_sprite("res/glyph2.png", 256, 256, (v2f) \
    {0, 0});
    for (int i = 5; i < 20; i++) {
        s.shoot[0].particles[i] = init_sprite("res/load.png", 128, 128, \
        (v2f) {0, 0});
        s.shoot[0].particles[i].rotation = 15 * i;
    }
    for (int i = 20; i < 25; i++) {
        s.shoot[0].particles[i] = init_sprite("res/blast0.png", 128, 128, \
        (v2f) {0, 0});
        s.shoot[0].particles[i].rotation = -60 + 30 * (i - 20);
    }
    return (s);
}

spell_t init_explosion2(spell_t s)
{
    s.clock = sfClock_create();
    s.second = 0;
    s.progress = 0;
    s.cooldown = 20;
    s.key = 0;
    s.state = 0;
    s.mana = 15;
    s.sound = create_sound("res/explosion_charge.ogg");
    s.sound2 = create_sound("res/explosion.ogg");
    s.UI = init_sprite("res/spell_explosion.png", 80, 80, (v2f) {1000, 800});
    s.UI.image = sfImage_createFromFile("res/spell_explosion.png");
    s.UI.func = explosion_func;
    s.UI.update = explosion_update;
    s.shoot = malloc(sizeof(gameobject_t));
    s.shoot[0].particles = malloc(sizeof(gameobject_t) * 100);
    s.shoot[0].particles[0] = init_sprite("res/glyph0.png", 256, 256, (v2f) \
    {0, 0});
    s.shoot[0].particles[1] = init_sprite("res/glyph1.png", 256, 256, (v2f) \
    {0, 0});
    return (s);
}

spell_t init_explosion(void)
{
    spell_t s;

    s = init_explosion2(s);
    s = init_explosion3(s);
    s = init_explosion4(s);
    for (int i = 45; i < 55; i++) {
        s.shoot[0].particles[i] = init_sprite("res/depo1.png", 32, 32, \
        (v2f) {0, 0});
        s.shoot[0].particles[i].rotation = -60 + 30 * (i - 45);
    }
    for (int i = 55; i < 100; i++)
        s.shoot[0].particles[i] = init_sprite("res/particles_2.png", 64, 64, \
        (v2f) {0, 0});
    return (s);
}
