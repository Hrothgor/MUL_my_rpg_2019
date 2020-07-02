/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** Map updater function
*/

#include "function.h"

sfRenderStates *blend_mode(sfTexture *texture)
{
    static int init = 0;
    static sfRenderStates *states;

    if (!init++) {
        states = malloc(sizeof(sfRenderStates));
        states->blendMode = sfBlendAdd;
        states->transform = (sfTransform) {{1, 1, 0, 0, 1, 0, 0, 0, 1}};
        states->shader = NULL;
    }
    states->texture = texture;
    return (states);
}

sfRenderStates *blend_moden(sfTexture *texture)
{
    static int init = 0;
    static sfRenderStates *states;

    if (!init++) {
        states = malloc(sizeof(sfRenderStates));
        states->blendMode = sfBlendAdd;
        states->transform = (sfTransform) {{1, 0, 0, 0, 1, 0, 0, 0, 1}};
        states->shader = NULL;
    }
    states->texture = texture;
    return (states);
}