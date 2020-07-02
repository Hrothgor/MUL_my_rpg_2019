/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

gameobject_t init_sprite(char *path, int width, int height, sfVector2f pos)
{
    gameobject_t ret;

    ret.sprite = sfSprite_create();
    ret.texture = sfTexture_createFromFile(path, NULL);
    ret.rect = (sfIntRect) {0, 0, width, height};
    ret.pos = pos;
    ret.color = sfWhite;
    ret.scale = (v2f) {1, 1};
    ret.rotation = 0;
    ret.name = path;
    ret.init = 1;
    return (ret);
}