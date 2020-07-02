/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

gameobject_t *init_button_scene_5(void)
{
    gameobject_t *button = malloc(sizeof(gameobject_t) * 4);

    button[0] = init_sprite("res/button.png", 250, 50, (v2f) {400, 450});
    button[0].rect.top = 500;
    button[0].func = button_alliance;
    button[1] = init_sprite("res/button.png", 250, 50, (v2f) {1200, 450});
    button[1].rect.top = 450;
    button[1].func = button_horde;
    button[2] = init_sprite("res/button.png", 250, 50, (v2f) {1200, 960});
    button[2].rect.top = 400;
    button[2].func = button_accept_create;
    button[3].init = 0;
    return (button);
}

gameobject_t *init_button_scene_6(void)
{
    gameobject_t *button = malloc(sizeof(gameobject_t) * 5);

    button[0] = init_sprite("res/button.png", 250, 50, (v2f) {835, 365});
    button[0].rect.top = 650;
    button[0].func = button_start;
    button[1] = init_sprite("res/button.png", 250, 50, (v2f) {835, 465});
    button[1].rect.top = 550;
    button[1].func = button_save;
    button[2] = init_sprite("res/button.png", 250, 50, (v2f) {835, 565});
    button[2].rect.top = 600;
    button[2].func = button_menu;
    button[3] = init_sprite("res/button.png", 250, 50, (v2f) {835, 665});
    button[3].rect.top = 150;
    button[3].func = button_quitter;
    button[4].init = 0;
    return (button);
}

gameobject_t *init_button_scene_7(void)
{
    gameobject_t *button = malloc(sizeof(gameobject_t) * 2);

    button[0] = init_sprite("res/button.png", 250, 50, (v2f) {1600, 850});
    button[0].rect.top = 200;
    button[0].func = button_menu;
    button[1].init = 0;
    return (button);
}

gameobject_t *init_button_scene_8(void)
{
    gameobject_t *button = malloc(sizeof(gameobject_t) * 2);

    button[0] = init_sprite("res/button.png", 250, 50, (v2f) {1600, 600});
    button[0].rect.top = 200;
    button[0].func = button_menu;
    button[1].init = 0;
    return (button);
}

gameobject_t **init_button(void)
{
    gameobject_t **button = malloc(sizeof(gameobject_t) * 9);

    button[0] = init_button_scene_0();
    button[1] = init_button_scene_1();
    button[2] = init_button_scene_2();
    button[3] = init_button_scene_3();
    button[4] = init_button_scene_4();
    button[5] = init_button_scene_5();
    button[6] = init_button_scene_6();
    button[7] = init_button_scene_7();
    button[8] = init_button_scene_8();
    return (button);
}