/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void particles_effect_blink(global_t *g, int n)
{
    float scale;

    for (int i = 5; i < 25; i++) {
        g->spell[n].shoot[0].particles[i].color.a = 255;
        g->spell[n].shoot[0].particles[i].pos = g->player.end_pos;
        scale = float_rand(1/4, 4/4);
        g->spell[n].shoot[0].particles[i].scale = (v2f) {scale, scale};
        g->spell[n].shoot[0].particles[i].angle = rand() % 360;
    }
    for (int i = 25; i < 45; i++) {
        g->spell[n].shoot[0].particles[i].color.a = 255;
        g->spell[n].shoot[0].particles[i].pos = g->player.e.data.pos;
        scale = float_rand(1/4, 4/4);
        g->spell[n].shoot[0].particles[i].scale = (v2f) {scale, scale};
        g->spell[n].shoot[0].particles[i].angle = rand() % 360;
    }
}

void blink_func2(void *tmp, int n, global_t *g)
{
    g->player.begin_pos = g->player.e.data.pos;
    g->player.end_pos = g->player.e.data.pos;
    g->player.end_pos.x += g->player.e.data.direction.x + 25;
    g->player.end_pos.y += g->player.e.data.direction.y + 25;
    g->player.e.data.pos = g->player.end_pos;
    for (int i = 0; i < 5; i++) {
        g->spell[n].shoot[0].particles[i].scale = (v2f) {1, 1};
        g->spell[n].shoot[0].particles[i].rotation = 1;
        g->spell[n].shoot[0].particles[i].color.a = 255;
    }
}

void blink_func(void *tmp, int n)
{
    global_t *g = tmp;

    g->player.e.data.angle = \
    atan2((g->mouse.y + g->view_pos.y) - g->player.e.data.pos.y + 25, \
    (g->mouse.x + g->view_pos.x) - g->player.e.data.pos.x + 25);
    g->player.e.data.direction.x = cosf(g->player.e.data.angle) * 500;
    g->player.e.data.direction.y = sinf(g->player.e.data.angle) * 500;
    if (collide(g) || collide_boss_map(g) || out_of_map(g)) {
        g->player.e.data.direction.x = 0;
        g->player.e.data.direction.y = 0;
        return;
    }
    play_sound(g->spell[n].sound, g, 2);
    blink_func2(tmp, n, g);
    particles_effect_blink(g, n);
}

spell_t init_blink2(spell_t s)
{
    s.shoot[0].particles = malloc(sizeof(gameobject_t) * 45);
    s.shoot[0].particles[0] = init_sprite("res/vortex.png", 64, 64, \
    (v2f) {0, 0});
    s.shoot[0].particles[0].color.a = 0;
    s.shoot[0].particles[1] = init_sprite("res/vortex.png", 64, 64, \
    (v2f) {0, 0});
    s.shoot[0].particles[2] = init_sprite("res/vortex2.png", 64, 64, \
    (v2f) {0, 0});
    s.shoot[0].particles[3] = init_sprite("res/vortex2.png", 64, 64, \
    (v2f) {0, 0});
    s.shoot[0].particles[4] = init_sprite("res/dash.png", 500, 500, \
    (v2f) {0, 0});
    for (int i = 5; i < 45; i++)
        s.shoot[0].particles[i] = init_sprite("res/particles_1.png", 64, 64, \
        (v2f) {0, 0});
    return (s);
}

spell_t init_blink(void)
{
    spell_t s;

    s.clock = sfClock_create();
    s.second = 0;
    s.progress = 0;
    s.cooldown = 3;
    s.key = 1;
    s.mana = 5;
    s.sound = create_sound("res/blink.ogg");
    s.UI = init_sprite("res/spell_blink.png", 80, 80, (v2f) {900, 800});
    s.UI.image = sfImage_createFromFile("res/spell_blink.png");
    s.UI.func = blink_func;
    s.UI.update = blink_update;
    s.shoot = malloc(sizeof(gameobject_t));
    s = init_blink2(s);
    return (s);
}
