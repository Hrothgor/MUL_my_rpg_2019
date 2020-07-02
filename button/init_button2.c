/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

gameobject_t *init_button_scene_0(void)
{
    gameobject_t *button = malloc(sizeof(gameobject_t) * 5);

    button[0] = init_sprite("res/button.png", 250, 50, (v2f) {850, 500});
    button[0].rect.top = 0;
    button[0].func = button_connexion;
    button[1] = init_sprite("res/button.png", 250, 50, (v2f) {100, 1000});
    button[1].rect.top = 100;
    button[1].func = button_htp;
    button[2] = init_sprite("res/button.png", 250, 50, (v2f) {1600, 1000});
    button[2].rect.top = 150;
    button[2].func = button_quitter;
    button[3] = init_sprite("res/button.png", 250, 50, (v2f) {850, 600});
    button[3].rect.top = 50;
    button[3].func = button_system_sound;
    button[4].init = 0;
    return (button);
}

gameobject_t *init_button_scene_1(void)
{
    gameobject_t *button = malloc(sizeof(gameobject_t) * 5);

    button[0] = init_sprite("res/icon_ui.png", 90, 90, (v2f) {1560, 990});
    button[0].rect.top = 90;
    button[0].func = button_display_quest;
    button[1] = init_sprite("res/icon_ui.png", 90, 90, (v2f) {1650, 990});
    button[1].rect.top = 0;
    button[1].func = button_display_inventory;
    button[2] = init_sprite("res/icon_ui.png", 90, 90, (v2f) {1740, 990});
    button[2].rect.top = 180;
    button[2].func = button_display_map;
    button[3] = init_sprite("res/icon_ui.png", 90, 90, (v2f) {1830, 990});
    button[3].rect.top = 270;
    button[3].func = button_pause;
    button[4].init = 0;
    return (button);
}

gameobject_t *init_button_scene_2(void)
{
    gameobject_t *button = malloc(sizeof(gameobject_t) * 4);

    button[0] = init_sprite("res/button.png", 250, 50, (v2f) {1600, 850});
    button[0].rect.top = 200;
    button[0].func = button_menu;
    button[1] = init_sprite("res/button.png", 250, 50, (v2f) {300, 200});
    button[1].rect.top = 250;
    button[1].func = button_system_sound;
    button[2] = init_sprite("res/button.png", 250, 50, (v2f) {300, 300});
    button[2].rect.top = 300;
    button[2].func = button_system_key;
    button[3].init = 0;
    return (button);
}

gameobject_t *init_button_scene_3(void)
{
    gameobject_t *button = malloc(sizeof(gameobject_t) * 6);

    button[0] = init_sprite("res/button.png", 250, 50, (v2f) {1600, 850});
    button[0].rect.top = 200;
    button[0].func = button_menu;
    button[1] = init_sprite("res/button.png", 250, 50, (v2f) {300, 200});
    button[1].rect.top = 250;
    button[1].func = button_system_sound;
    button[2] = init_sprite("res/button.png", 250, 50, (v2f) {300, 300});
    button[2].rect.top = 300;
    button[2].func = button_system_key;
    button[3] = init_sprite("res/button1.png", 50, 50, (v2f) {1467, 160});
    button[3].rect.top = 50;
    button[3].func = button_key_slide_up;
    button[4] = init_sprite("res/button1.png", 50, 50, (v2f) {1467, 900});
    button[4].rect.top = 0;
    button[4].func = button_key_slide_down;
    button[5].init = 0;
    return (button);
}

gameobject_t *init_button_scene_4(void)
{
    gameobject_t *button = malloc(sizeof(gameobject_t) * 4);

    button[0] = init_sprite("res/button.png", 250, 50, (v2f) {1540, 970});
    button[0].rect.top = 200;
    button[0].func = button_menu;
    button[1] = init_sprite("res/button.png", 250, 50, (v2f) {820, 990});
    button[1].rect.top = 350;
    button[1].func = button_start;
    button[2] = init_sprite("res/button.png", 250, 50, (v2f) {1540, 860});
    button[2].rect.top = 400;
    button[2].func = button_create;
    button[3].init = 0;
    return (button);
}
