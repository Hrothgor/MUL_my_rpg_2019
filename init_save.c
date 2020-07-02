/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

save_t init_player_dirent2(save_t ret, char **arr, int i, global_t *g)
{
    char **items_id = my_str_to_word_array_char(arr[3], ',');

    for (int i = 0; items_id[i]; i++) {
        if (my_atoi(items_id[i]) == 0) {
            ret.data.inventory[i].item.init = 0;
            ret.data.inventory[i].item.rect.height = 80;
            ret.data.inventory[i].item.rect.width = 80;
        } else
            ret.data.inventory[i] = g->items[my_atoi(items_id[i]) - 1];
    }
    ret.data.e.data.pos.x = my_atoi(arr[4]);
    ret.data.e.data.pos.y = my_atoi(arr[5]);
    ret.data.nb_quest = my_atoi(arr[6]);
    ret.data.end = my_atoi(arr[7]);
    return (ret);
}

save_t init_player_dirent(struct dirent *dir, char **arr, int i, global_t *g)
{
    save_t ret;

    ret.data = init_player(g);
    ret.bg = init_sprite("res/button_save.png", \
    400, 100, (v2f) {1470, 60 + 100 * i});
    ret.data.e.name = my_strdup(dir->d_name);
    ret.data.e.level = my_atoi(arr[0]);
    ret.data.gold = my_atoi(arr[1]);
    ret.data.race = my_atoi(arr[2]);
    if (ret.data.race == 0)
        ret.data.e.data.texture = \
        sfTexture_createFromFile("res/play_1.png", NULL);
    if (ret.data.race == 1)
        ret.data.e.data.texture = \
        sfTexture_createFromFile("res/play_2.png", NULL);
    return (init_player_dirent2(ret, arr, i, g));
}

save_t *init_save(char *path, global_t *g)
{
    save_t *ret = malloc(sizeof(save_t) * (calc_nb_quest(path) + 1));
    DIR *dir = opendir(path);
    struct dirent *dirent;
    char **arr;
    int i = 0;

    ret[calc_nb_quest(path)].bg.init = 0;
    while ((dirent = readdir(dir)) != NULL) {
        if (dirent->d_name[0] != '.') {
            arr = my_str_to_word_array_char(read_map(\
            my_strcat(my_strcat(path, "/"), dirent->d_name)), '\n');
            ret[i] = init_player_dirent(dirent, arr, i, g);
            i++;
        }
    }
    closedir(dir);
    return (ret);
}