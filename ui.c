/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

item_t item_from_char(char *name, global_t *g)
{
    for (int i = 0; g->items[i].item.init; i++)
        if (my_strcmp(name, g->items[i].item.name))
            return (g->items[i]);
    return (g->items[0]);
}

int item_in_inventory(char *name, global_t *g)
{
    for (int i = 0; i < 34; i++)
        if (g->player.inventory[i].item.init)
            if (my_strcmp(name, g->player.inventory[i].item.name))
                return (1);
    return (0);
}

void update_ui(global_t *g)
{
    update_spell_ui(g);
    update_quest_interface_ui(g);
    update_inventory_interface_ui(g);
    update_vendor_interface_ui(g);
    update_map_ui(g);
}