/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

item_t init_items_dirent(struct dirent *dirent, char **arr, int i)
{
    item_t ret;

    ret.ID = i+1;
    ret.item = init_sprite(my_strcat(my_strcat("res/", dirent->d_name), \
    "_item.png"), 80, 80, (sfVector2f) {0, 0});
    ret.item.name = my_strdup(dirent->d_name);
    ret.drop_rate = (float) my_atoi(arr[0]);
    ret.drop_max = my_atoi(arr[1]);
    ret.price = (float) my_atoi(arr[2]);
    ret.arr = my_str_to_word_array_char(arr[3], ',');
    ret.slot = my_atoi(arr[4]);
    ret.level = my_atoi(arr[5]);
    return (ret);
}

item_t *init_items(char *path)
{
    item_t *ret = malloc(sizeof(item_t) * (calc_nb_quest(path) + 1));
    DIR *dir = opendir(path);
    struct dirent *dirent;
    char **arr;
    int i = 0;

    ret[calc_nb_quest(path)].item.init = 0;
    while ((dirent = readdir(dir)) != NULL) {
        if (dirent->d_name[0] != '.') {
            arr = my_str_to_word_array_char(read_map(\
            my_strcat(my_strcat(path, "/"), dirent->d_name)), '\n');
            ret[i] = init_items_dirent(dirent, arr, i);
            i++;
        }
    }
    closedir(dir);
    return (ret);
}