/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "function.h"

int calc_nb_quest(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *dirent;
    int ret = 0;

    while ((dirent = readdir(dir)) != NULL)
        if (dirent->d_name[0] != '.')
            ret += 1;
    closedir(dir);
    return (ret);
}

quest_t init_quest_dirent(struct dirent *dirent, char **arr, int i)
{
    quest_t ret;

    ret.name = my_strdup(dirent->d_name);
    ret.ID = i;
    ret.bg = init_sprite("res/interface_model.png", 450, 550, \
    (sfVector2f) {100, 100});
    ret.icone = init_sprite(arr[0], 50, 50, (sfVector2f) {115, 117});
    ret.npc = arr[1];
    ret.txt1 = arr[2];
    ret.txt2 = arr[3];
    return (ret);
}

quest_t *init_quest(char *path)
{
    quest_t *ret = malloc(sizeof(quest_t) * (calc_nb_quest(path) + 1));
    DIR *dir = opendir(path);
    struct dirent *dirent;
    char **arr;
    int i = 0;

    ret[calc_nb_quest(path)].icone.init = 0;
    while ((dirent = readdir(dir)) != NULL) {
        if (dirent->d_name[0] != '.') {
            i = dirent->d_name[0] - '0';
            arr = my_str_to_word_array_char(read_map(\
            my_strcat(my_strcat(path, "/"), dirent->d_name)), '\n');
            ret[i] = init_quest_dirent(dirent, arr, i);
        }
    }
    closedir(dir);
    return (ret);
}