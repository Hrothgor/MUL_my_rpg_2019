/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

int *init_key(void)
{
    int *ret = malloc(sizeof(int) * 24);

    for (int i = 0; i < 24; i++)
        ret[i] = -1;
    ret[0] = sfKeyZ;
    ret[1] = sfKeyS;
    ret[2] = sfKeyQ;
    ret[3] = sfKeyD;
    ret[4] = sfKeyLShift;
    ret[5] = sfKeyLAlt;
    ret[6] = sfKeyNum3;
    ret[7] = sfKeyNum4;
    ret[8] = sfKeyNum5;
    ret[9] = sfKeyNum6;
    ret[10] = sfKeyNum7;
    ret[11] = sfKeyNum8;
    ret[12] = sfKeyNum9;
    ret[13] = sfKeyNum0;
    return (ret);
}

map_t init_map(void)
{
    map_t map;

    map.bottom = init_sprite("res/map0.png", 4800, 4800, (v2f) {0, 0});
    map.top = init_sprite("res/map1.png", 4800, 4800, (v2f) {0, 0});
    map.bottom.scale = (v2f) {2, 2};
    map.top.scale = (v2f) {2, 2};
    map.bottom2 = init_sprite("res/map2.png", 600, 600, (v2f) {20000, 20000});
    map.top2 = init_sprite("res/map3.png", 600, 600, (v2f) {20000, 20000});
    map.bottom2.scale = (v2f) {2.5, 2.5};
    map.top2.scale = (v2f) {2.5, 2.5};
    return (map);
}

sfView *init_view(void)
{
    sfView *view;

    view = sfView_create();
    sfView_setSize(view, (v2f) {1920, 1080});
    sfView_setCenter(view, (v2f) {960, 540});
    return (view);
}

global_t *init_global_bis(sfRenderWindow *window, global_t *g)
{
    g->scene = 0;
    g->song = create_sound("res/menu.ogg");
    sfSound_setLoop(g->song, sfTrue);
    g->event.key = malloc(sizeof(int) * sfKeyCount);
    g->window = window;
    g->key.sliding = 0;
    g->key.key = init_key();
    g->map = init_map();
    g->view = init_view();
    g->player = init_player(g);
    init_spell(g);
    g->quest = init_quest("quest");
    g->items = init_items("items");
    g->save = init_save("save", g);
    g->button = init_button();
    return (g);
}

global_t *init_global(sfRenderWindow *window)
{
    global_t *g = malloc(sizeof(global_t));

    init_global_bis(window, g);
    init_ennemi(g);
    init_pnj(g);
    init_boss(g);
    g->text_middle = init_text_middle(40);
    g->view_pos.x = g->player.e.data.pos.x - 960;
    g->view_pos.y = g->player.e.data.pos.y - 540;
    g->ui_inventory = 0;
    g->ui_quest = 0;
    g->ui_map = 0;
    g->ui_shop = 0;
    g->item_selec.item.init = 0;
    g->volume_master = 50;
    g->volume_music = 50;
    g->volume_sound = 50;
    g->volume_spell = 50;
    g->frame_update = NULL;
    return (g);
}
