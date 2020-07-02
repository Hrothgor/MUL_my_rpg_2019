/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void give_player_item(item_t item, global_t *g)
{
    for (int i = 0; i < 30; i++)
        if (g->player.inventory[i].item.init == 0) {
            g->player.inventory[i] = item;
            return;
        }
}

void drop_items(ennemi_t ennemi, global_t *g)
{
    int random_rate = 0;
    int random_max = 0;
    int check = 0;

    for (int i = 0; g->items[i].item.init; i++) {
        check = 0;
        for (int j = 0; g->items[i].arr[j]; j++)
            if (my_strcmp(g->items[i].arr[j], ennemi.name))
                check = 1;
        if (check == 0)
            continue;
        random_rate = rand() % 100;
        random_max = (rand() % (g->items[i].drop_max)) + 1;
        if (random_rate <= g->items[i].drop_rate)
            for (int j = 0; j < random_max; j++)
                give_player_item(g->items[i], g);
    }
}

void update_pos_item_in_inventory(global_t *g)
{
    sfVector2f pos_ui;

    pos_ui.x = 1200 + 18;
    pos_ui.y = 300 + 14;
    for (int i = 0; i < 30; i++) {
        g->player.inventory[i].item.pos.x = pos_ui.x + (i % 6) * 89 + 5;
        g->player.inventory[i].item.pos.y = pos_ui.y + (i / 6) * 89 + 5;
    }
    pos_ui.x = 1075 + 18;
    for (int i = 30; i < 34; i++) {
        g->player.inventory[i].item.pos.x = pos_ui.x + 5;
        g->player.inventory[i].item.pos.y = pos_ui.y + (i - 30) * 89 + 5;
    }
}

void display_info_text_item(global_t *g, text_info_t text, \
sfVector2f pos, item_t item)
{
    text.color = (sfColor) {246, 192, 0, 255};
    text.pos = (v2f) {pos.x + 10, pos.y + 5};
    text.data = my_strcat("Item name: ", my_strdup(item.item.name));
    draw_text_ui(text, g->view_pos, g->window);
    text.pos.y += 50;
    text.data = my_strcat("Item sell price: ", my_itostr(item.price));
    draw_text_ui(text, g->view_pos, g->window);
    text.pos.y += 50;
    if (item.level != 0) {
        text.data = my_strcat("Item level: ", my_itostr(item.level));
        text.color = sfGreen;
    } else {
        text.data = my_strdup("Cannot be equipped");
        text.color = sfRed;
    }
    draw_text_ui(text, g->view_pos, g->window);
    free(text.data);
}

void display_info_item(global_t *g)
{
    static int init = 0;
    static gameobject_t bg;
    static text_info_t text;

    if (!init++) {
        bg = init_sprite("res/info_item.png", 450, 150, (v2f) {0, 0});
        text = init_text_sys(30, NULL, (v2f) {0, 0});
        sfText_setOutlineThickness(text.text, 2);
    }
    for (int i = 0; i < 34; i++) {
        if (hover_button_ui(g->player.inventory[i].item, g->window, g)) {
            bg.pos.x = g->player.inventory[i].item.pos.x - 460;
            bg.pos.y = g->player.inventory[i].item.pos.y - 35;
            draw_ui(bg, g->view_pos, g->window);
            display_info_text_item(g, text, bg.pos, g->player.inventory[i]);
        }
    }
}