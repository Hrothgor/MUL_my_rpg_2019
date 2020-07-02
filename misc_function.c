/*
** EPITECH PROJECT, 2019
** window.c
** File description:
** init and update window
*/

#include "function.h"

void draw_text(text_info_t texte, sfRenderWindow *window)
{
    sfText_setCharacterSize(texte.text, texte.size);
    sfText_setString(texte.text, texte.data);
    sfText_setFont(texte.text, texte.font);
    sfText_setColor (texte.text, texte.color);
    sfText_setPosition (texte.text, texte.pos);
    sfRenderWindow_drawText(window, texte.text, NULL);
}

void draw_text_ui(text_info_t texte, \
sfVector2f view_pos, sfRenderWindow *window)
{
    sfVector2f pos;

    pos.x = texte.pos.x + view_pos.x;
    pos.y = texte.pos.y + view_pos.y;
    sfText_setCharacterSize(texte.text, texte.size);
    sfText_setString(texte.text, texte.data);
    sfText_setFont(texte.text, texte.font);
    sfText_setColor (texte.text, texte.color);
    sfText_setPosition (texte.text, pos);
    sfRenderWindow_drawText(window, texte.text, NULL);
}

void move_rect(sfIntRect *rect, int offset, int reset, int max_value)
{
    if (rect->left + offset < max_value)
        rect->left += offset;
    else
        rect->left = reset;
}

sfRectangleShape *create_rectangle(sfColor color)
{
    sfRectangleShape *ret = sfRectangleShape_create();

    sfRectangleShape_setFillColor(ret, color);
    return (ret);
}

sfSound *create_sound(char *path)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *soundbuffer = sfSoundBuffer_createFromFile(path);

    sfSound_setBuffer(sound, soundbuffer);
    return (sound);
}
