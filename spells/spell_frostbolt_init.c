/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void frostbolt_func2(void *tmp, int n)
{
    global_t *g = tmp;
    static int sound = 0;

    if (sound == 0)
        play_sound(g->spell[n].sound, g, 2);
    if (sound == 1)
        play_sound(g->spell[n].sound2, g, 2);
    if (sound == 2)
        play_sound(g->spell[n].sound3, g, 2);
    if (sound == 3)
        play_sound(g->spell[n].sound4, g, 2);
    sound++;
    if (sound == 4)
        sound = 0;
}

void frostbolt_func(void *tmp, int n)
{
    global_t *g = tmp;

    frostbolt_func2(tmp, n);
    for (int i = 0; i < 40; i++) {
        if (!g->spell[n].shoot[i].init) {
            g->spell[n].shoot[i].init = 1;
            g->spell[n].shoot[i].pos.x = g->player.e.data.pos.x + 25;
            g->spell[n].shoot[i].pos.y = g->player.e.data.pos.y + 25;
            g->spell[n].shoot[i].angle = atan2((g->mouse.y - 64 + \
            g->view_pos.y) - g->player.e.data.pos.y + 25, \
            (g->mouse.x - 64 + g->view_pos.x) - g->player.e.data.pos.x + 25);
            g->spell[n].shoot[i].direction.x = \
            cosf(g->spell[n].shoot[i].angle) * 30;
            g->spell[n].shoot[i].direction.y = \
            sinf(g->spell[n].shoot[i].angle) * 30;
            init_frostbolt_particles(g, g->spell[n].shoot[i]);
            break;
        }
    }
}

spell_t init_frostbolt2(spell_t s)
{
    s.clock = sfClock_create();
    s.second = 0;
    s.progress = 0;
    s.cooldown = 0.2;
    s.key = 2;
    s.mana = 5;
    s.sound = create_sound("res/frost1");
    s.sound2 = create_sound("res/frost2");
    s.sound3 = create_sound("res/frost3");
    s.sound4 = create_sound("res/frost4");
    s.UI = init_sprite("res/spell_frostbolt.png", 80, 80, (v2f) {800, 800});
    s.UI.image = sfImage_createFromFile("res/spell_frostbolt.png");
    s.UI.func = frostbolt_func;
    s.UI.update = frostbolt_update;
    s.shoot = malloc(sizeof(gameobject_t) * 40);
    return (s);
}

spell_t init_frostbolt(void)
{
    spell_t s;

    s = init_frostbolt2(s);
    for (int i = 0; i < 40; i++) {
        s.shoot[i] = init_sprite("res/frostbolt.png", 128, 128, (v2f) {0, 0});
        s.shoot[i].init = 0;
        s.shoot[i].particles = malloc(sizeof(gameobject_t) * 40);
        for (int j = 0; j < 40; j++) {
            s.shoot[i].particles[j] = init_sprite(\
            "res/particles_1.png", 64, 64, (v2f) {0, 0});
            s.shoot[i].particles[j].init = 0;
        }
    }
    return (s);
}
