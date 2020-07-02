/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

int move_item_in_equipement(int pos_selec, int check, global_t *g)
{
    int last_init = 0;

    if (check == 1)
        return (check);
    for (int i = 30; i < 34; i++) {
        last_init = g->player.inventory[i].item.init;
        g->player.inventory[i].item.init = 1;
        if (hover_button_ui(g->player.inventory[i].item, g->window, g) \
        && i - 30 + 1 == g->item_selec.slot) {
            g->player.inventory[i].item.init = last_init;
            check = 1;
            g->player.inventory[pos_selec] = g->player.inventory[i];
            g->player.inventory[i] = g->item_selec;
            break;
        }
        g->player.inventory[i].item.init = last_init;
    }
    return (check);
}

void move_item_in_inventory_2(int pos_selec, int check, \
global_t *g, int last_init)
{
    if (g->item_selec.item.init && g->event.mouseLup) {
        for (int i = 0; i < 30; i++) {
            last_init = g->player.inventory[i].item.init;
            g->player.inventory[i].item.init = 1;
            if (hover_button_ui(g->player.inventory[i].item, g->window, g)) {
                g->player.inventory[i].item.init = last_init;
                check = 1;
                g->player.inventory[pos_selec] = g->player.inventory[i];
                g->player.inventory[i] = g->item_selec;
                break;
            }
            g->player.inventory[i].item.init = last_init;
        }
        check = move_item_in_equipement(pos_selec, check, g);
        if (check == 0)
            g->player.inventory[pos_selec] = g->item_selec;
        g->item_selec.item.init = 0;
    }
}

void move_item_in_inventory(global_t *g)
{
    static int pos_selec = 0;
    sfVector2f mouse;

    mouse.x = sfMouse_getPositionRenderWindow(g->window).x;
    mouse.y = sfMouse_getPositionRenderWindow(g->window).y;
    for (int i = 0; i < 34; i++) {
        if (!g->item_selec.item.init && g->event.mouseLdown && \
        hover_button_ui(g->player.inventory[i].item, g->window, g)) {
            pos_selec = i;
            g->item_selec = g->player.inventory[i];
            g->player.inventory[i].item.init = 0;
        }
    }
    move_item_in_inventory_2(pos_selec, 0, g, 0);
    if (g->item_selec.item.init) {
        g->item_selec.item.pos.x = mouse.x - 40;
        g->item_selec.item.pos.y = mouse.y - 40;
    }
}

void draw_gold(global_t *g, sfVector2f pos, int gold)
{
    static int init = 0;
    static text_info_t text;
    static gameobject_t bg;
    sfFloatRect rect;

    if (!init++) {
        text = init_text_sys(24, NULL, (v2f) {0, 0});
        text.color = sfWhite;
        bg = init_sprite("res/gold.png", 26, 26, (v2f) {0, 0});
    }
    bg.pos = pos;
    draw_ui(bg, g->view_pos, g->window);
    text.data = my_itostr(gold);
    text.pos.y = pos.y;
    text.pos.x = -1000;
    draw_text_ui(text, g->view_pos, g->window);
    rect = sfText_getLocalBounds(text.text);
    text.pos.x = pos.x - rect.width - 5;
    draw_text_ui(text, g->view_pos, g->window);
    free(text.data);
}

void update_inventory_interface_ui(global_t *g)
{
    static int init = 0;
    static gameobject_t ui;

    if (!init++)
        ui = init_sprite("res/inventory_ui.png", 695, 540, (v2f) {1075, 300});
    if (g->ui_inventory == 1) {
        draw_ui(ui, g->view_pos, g->window);
        update_pos_item_in_inventory(g);
        move_item_in_inventory(g);
        for (int i = 0; i < 34; i++)
            draw_ui(g->player.inventory[i].item, g->view_pos, g->window);
        display_info_item(g);
        draw_ui(g->item_selec.item, g->view_pos, g->window);
        draw_gold(g, (v2f) {1700, 783}, g->player.gold);
    }
}