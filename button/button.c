/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** parralax function
*/

#include "function.h"

int hover_button(gameobject_t obj, sfRenderWindow *win, global_t *g)
{
    sfVector2i m_pos = {0, 0};

    if (!obj.init)
        return (0);
    m_pos = sfMouse_getPositionRenderWindow(win);
    m_pos.x += g->view_pos.x;
    m_pos.y += g->view_pos.y;
    if (m_pos.x >= obj.pos.x && m_pos.x <= obj.pos.x + obj.rect.width && \
    m_pos.y >= obj.pos.y && m_pos.y <= obj.pos.y + obj.rect.height)
        return (1);
    return (0);
}

int hover_button_ui(gameobject_t obj, sfRenderWindow *win, global_t *g)
{
    sfVector2i m_pos = {0, 0};

    if (!obj.init)
        return (0);
    m_pos = sfMouse_getPositionRenderWindow(win);
    if (m_pos.x >= obj.pos.x && m_pos.x <= obj.pos.x + obj.rect.width && \
    m_pos.y >= obj.pos.y && m_pos.y <= obj.pos.y + obj.rect.height)
        return (1);
    return (0);
}
