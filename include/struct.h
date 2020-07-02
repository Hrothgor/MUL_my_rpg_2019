/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** All function prototype
*/

#include "include.h"

typedef struct text_info {
    sfText *text;
    sfFont *font;
    int size;
    char *data;
    sfColor color;
    sfVector2f pos;
} text_info_t;

typedef struct gameobject {
    sfSprite *sprite;
    sfTexture *texture;
    sfImage *image;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    sfColor color;
    float rotation;
    char *name;
    int init;
    int speed;
    float angle;
    sfVector2f direction;
    struct gameobject *particles;
    void (*func)(void *, int);
    void (*update)(void *, int);
} gameobject_t;

typedef struct quest {
    int ID;
    char *name;
    char *npc;
    gameobject_t icone;
    gameobject_t bg;
    char *txt1;
    char *txt2;
} quest_t;

typedef struct spell {
    sfClock *clock;
    float second;
    float progress;
    sfKeyCode key;
    float cooldown;
    int state;
    int mana;
    gameobject_t UI;
    gameobject_t *shoot;
    sfSound *sound;
    sfSound *sound2;
    sfSound *sound3;
    sfSound *sound4;
} spell_t;

typedef struct entity {
    int level;
    float mana;
    float maxmana;
    float hp;
    float maxhp;
    char *name;
    gameobject_t data;
    gameobject_t icone;
} entity_t;

typedef struct map {
    gameobject_t bottom;
    gameobject_t top;
    gameobject_t bottom2;
    gameobject_t top2;
} map_t;

typedef struct ennemi {
    sfClock *clock;
    sfClock *animation;
    sfClock *respawn;
    sfIntRect zone;
    float second;
    float respawn_second;
    float idle_second;
    float idle_time;
    int ID;
    char *name;
    int xp;
    float speed;
    int dmg;
    int dps;
    int agro;
    int range;
    int status;
    int ranged;
    entity_t e;
    gameobject_t l;
    gameobject_t lb;
} ennemi_t;

typedef struct boss {
    sfClock *clock;
    sfClock *animation;
    float second;
    int ID;
    int phase;
    char *name;
    int xp;
    float speed;
    int dmg;
    int dps;
    int agro;
    int range;
    int invul;
    int creeps;
    entity_t e;
    gameobject_t l;
    gameobject_t lb;
} boss_t;

typedef struct pnj {
    entity_t e;
    quest_t quest;
    int talked;
    int state;
} pnj_t;

typedef struct item {
    gameobject_t item;
    int ID;
    float drop_rate;
    int drop_max;
    float price;
    char **arr;
    int slot;
    int level;
} item_t;

typedef struct player {
    sfClock *clock;
    float second;
    entity_t e;
    int shield;
    item_t *inventory;
    float gold;
    int race;
    sfVector2f begin_pos;
    sfVector2f end_pos;
    int nb_quest;
    int map;
    int end;
} player_t;

typedef struct event {
    int mouseLup;
    int mouseLdown;
    int mouseRup;
    int mouseRdown;
    int *key;
} event_t;

typedef struct key {
    int sliding;
    int *key;
} keyy_t;

typedef struct save {
    player_t data;
    gameobject_t bg;
} save_t;

typedef struct global {
    int scene;
    event_t event;
    sfSound *song;
    sfRenderWindow *window;
    gameobject_t **button;
    player_t player;
    save_t *save;
    ennemi_t *ennemi;
    pnj_t *pnj;
    spell_t *spell;
    quest_t *quest;
    entity_t frame;
    entity_t *frame_update;
    sfVector2i mouse;
    map_t map;
    boss_t *boss;
    sfView *view;
    keyy_t key;
    sfVector2f view_pos;
    text_info_t text_middle;
    item_t *items;
    item_t item_selec;
    int ui_quest;
    int ui_inventory;
    int ui_map;
    int ui_shop;
    int volume_master;
    int volume_spell;
    int volume_music;
    int volume_sound;
} global_t;
