/*
** EPITECH PROJECT, 2019
** window.c
** File description:
** init and update window
*/

#include "function.h"

float float_rand(float min, float max)
{
    float scale = rand() / (float) RAND_MAX;
    return (min + scale * (max - min));
}

void draw(gameobject_t object, sfRenderWindow *window)
{
    if (!object.init)
        return;
    sfSprite_setScale(object.sprite, object.scale);
    sfSprite_setPosition(object.sprite, object.pos);
    sfSprite_setColor(object.sprite, object.color);
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    sfSprite_setTextureRect(object.sprite, object.rect);
    sfRenderWindow_drawSprite(window, object.sprite, NULL);
}

void draw_ui(gameobject_t object, sfVector2f view_pos, sfRenderWindow *window)
{
    sfVector2f pos;

    if (!object.init)
        return;
    pos.x = object.pos.x + view_pos.x;
    pos.y = object.pos.y + view_pos.y;
    sfSprite_setScale(object.sprite, object.scale);
    sfSprite_setPosition(object.sprite, pos);
    sfSprite_setColor(object.sprite, object.color);
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    sfSprite_setTextureRect(object.sprite, object.rect);
    sfRenderWindow_drawSprite(window, object.sprite, NULL);
}

void draw_mode(gameobject_t o, sfRenderStates *mode, sfRenderWindow *w)
{
    if (!o.init)
        return;
    sfSprite_setScale(o.sprite, o.scale);
    sfSprite_setOrigin(o.sprite, (v2f) \
    {sfTexture_getSize(o.texture).x / 2, sfTexture_getSize(o.texture).y / 2});
    sfSprite_setRotation(o.sprite, o.rotation);
    sfSprite_setColor(o.sprite, o.color);
    sfSprite_setPosition(o.sprite, o.pos);
    sfSprite_setTexture(o.sprite, o.texture, sfTrue);
    sfSprite_setTextureRect(o.sprite, o.rect);
    sfRenderWindow_drawSprite(w, o.sprite, mode);
}

void draw_mode_ui(gameobject_t o, sfVector2f view_pos, \
sfRenderStates *mode, sfRenderWindow *w)
{
    sfVector2f pos;

    if (!o.init)
        return;
    pos.x = o.pos.x + view_pos.x;
    pos.y = o.pos.y + view_pos.y;
    sfSprite_setScale(o.sprite, o.scale);
    sfSprite_setOrigin(o.sprite, (v2f) \
    {sfTexture_getSize(o.texture).x / 2, sfTexture_getSize(o.texture).y / 2});
    sfSprite_setRotation(o.sprite, o.rotation);
    sfSprite_setColor(o.sprite, o.color);
    sfSprite_setPosition(o.sprite, pos);
    sfSprite_setTexture(o.sprite, o.texture, sfTrue);
    sfSprite_setTextureRect(o.sprite, o.rect);
    sfRenderWindow_drawSprite(w, o.sprite, mode);
}