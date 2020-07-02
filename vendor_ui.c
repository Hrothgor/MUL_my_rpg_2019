/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

void update_selling_items(global_t *g)
{
    static sfSound *sound = NULL;

    if (sound == NULL)
        sound = create_sound("res/vendor.ogg");
    if (g->ui_inventory) {
        for (int i = 0; i < 34; i++) {
            if (g->player.inventory[i].item.init && \
            hover_button_ui(g->player.inventory[i].item, g->window, g) && \
            g->event.mouseRup) {
                g->player.inventory[i].item.init = 0;
                g->player.gold += g->player.inventory[i].price;
                play_sound(sound, g, 0);
            }
        }
    }
    if (pythagore(g->player.e.data.pos.x - g->pnj[g->ui_shop-1].e.data.pos.x, \
    g->player.e.data.pos.y - g->pnj[g->ui_shop-1].e.data.pos.y) > 150 * 150) {
        g->ui_shop = 0;
        play_sound(sound, g, 0);
    }
}

void draw_text_item_buy(global_t *g, item_t item)
{
    static int init = 0;
    static text_info_t text;

    if (!init++) {
        text = init_text_sys(26, NULL, (v2f) {225, 205});
        text.color = sfWhite;
        sfText_setOutlineThickness(text.text, 2);
    }
    text.data = my_strdup(item.item.name);
    draw_text_ui(text, g->view_pos, g->window);
    draw_gold(g, (v2f) {415, 273}, item.price);
    free(text.data);
}

void update_buying_item(global_t *g)
{
    static int init = 0;
    static item_t item;
    static sfSound *sound;

    if (!init++) {
        sound = create_sound("res/vendor.ogg");
        item = item_from_char("dungeon_key", g);
        item.item.pos = (v2f) {126, 197};
    }
    draw_ui(item.item, g->view_pos, g->window);
    draw_text_item_buy(g, item);
    if (hover_button_ui(item.item, g->window, g) && g->event.mouseRup && \
    g->player.gold >= item.price) {
        g->player.gold -= item.price;
        give_player_item(item, g);
        play_sound(sound, g, 0);
    }
}

void update_vendor_interface_ui(global_t *g)
{
    static int init = 0;
    static gameobject_t bg;

    if (!init++)
        bg = init_sprite("res/vendor_ui.png", 450, 550, (v2f) {100, 100});
    if (g->ui_shop != 0) {
        draw_ui(bg, g->view_pos, g->window);
        update_selling_items(g);
        update_buying_item(g);
        draw_gold(g, (v2f) {500, 600}, g->player.gold);
    }
}