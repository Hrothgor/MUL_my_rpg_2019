/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** All function prototype
*/

#include "my.h"
#include "global.h"
#include "include.h"

void poll_event(global_t *, sfEvent);
void update(sfRenderWindow *, sfEvent);

//////// INIT_BUTTON ////////

gameobject_t *init_button_scene_0(void);
gameobject_t *init_button_scene_1(void);
gameobject_t *init_button_scene_2(void);
gameobject_t *init_button_scene_3(void);
gameobject_t *init_button_scene_4(void);
gameobject_t *init_button_scene_5(void);
gameobject_t **init_button(void);

//////// INIT_ALL ////////

gameobject_t init_sprite(char *path, int width, int height, sfVector2f pos);
global_t *init_global(sfRenderWindow *window);
quest_t *init_quest(char *path);
item_t *init_items(char *path);
void init_spell(global_t *g);

//////// MISC_FUNC ////////

float float_rand(float min, float max);
void draw(gameobject_t object, sfRenderWindow *window);
void draw_ui(gameobject_t object, sfVector2f view_pos, sfRenderWindow *window);
void move_rect(sfIntRect *rect, int offset, int reset, int max_value);
sfSound *create_sound(char *path);
sfRectangleShape *create_rectangle(sfColor color);
void draw_text(text_info_t texte, sfRenderWindow *window);
void draw_text_ui(text_info_t texte, \
sfVector2f view_pos, sfRenderWindow *window);
char *read_map(char *filepath);
void draw_mode_ui(gameobject_t o, sfVector2f view_pos, \
sfRenderStates *mode, sfRenderWindow *w);
int calc_nb_quest(char *path);
void play_sound(sfSound *sound, global_t *g, int i);

//////// BUTTON ////////

int hover_button(gameobject_t obj, sfRenderWindow *win, global_t *g);
int hover_button_ui(gameobject_t obj, sfRenderWindow *win, global_t *g);

//////// BUTTON_FUNC ////////

void button_display_quest(void *tmp, int i);
void button_display_inventory(void *tmp, int i);
void button_start(void *tmp, int i);
void button_connexion(void *tmp, int i);
void button_menu(void *tmp, int i);
void button_system_sound(void *tmp, int i);
void button_system_key(void *tmp, int i);
void button_quitter(void *tmp, int i);
void button_sound_up(void *tmp, int i);
void button_sound_down(void *tmp, int i);
void button_key_slide_down(void *tmp, int i);
void button_key_slide_up(void *tmp, int i);
void button_useless(void *tmp, int i);
void button_create(void *tmp, int i);
void button_alliance(void *tmp, int i);
void button_horde(void *tmp, int i);
void button_display_map(void *tmp, int i);
void button_accept_create(void *tmp, int i);
void button_save(void *tmp, int i);
void button_pause(void *tmp, int i);
void button_htp(void *tmp, int i);

//////// SCENE ////////

void scene_0(global_t *g);
void scene_1(global_t *g);
void scene_2(global_t *g);
void scene_3(global_t *g);
void scene_4(global_t *g);
void scene_5(global_t *g);
void scene_6(global_t *g);
void scene_7(global_t *g);
void scene_8(global_t *g);

//////// PARTICLES ////////

sfRenderStates *blend_moden(sfTexture *texture);
sfRenderStates *blend_mode(sfTexture *texture);
void draw_mode(gameobject_t o, sfRenderStates *mode, sfRenderWindow *w);
void particles_effect_scene_0(global_t *g);

//////// PLAYER ////////

player_t init_player(global_t *g);
void update_player(global_t *g);
int collide(global_t *g);
void update_level_player(global_t *g);
void update_spell_player(global_t *g);
void player_death(global_t *g);
int out_of_map(global_t *g);
int collide_boss_map(global_t *g);

//////// SYS_SLIDER ////////

text_info_t init_text_sys(int size, char *data, sfVector2f pos);
void update_slider_0(global_t *g);
void update_slider_1(global_t *g);
void update_slider_2(global_t *g);
void update_slider_3(global_t *g);

//////// SYS_KEY_CHANGE ////////

void update_slider_key(global_t *g);
void update_key_change(global_t *g);

//////// PRINT_KEY ////////

char *print_key(int a);

//////// UPDATE_SPELL ////////

sfImage *cd_update_text(sfImage *image, float progress, sfColor overlay);

//////// SPELLS ////////

spell_t init_frostbolt(void);
void frostbolt_func(void *tmp, int n);
void frostbolt_update(void *tmp, int n);
void init_frostbolt_particles(global_t *g, gameobject_t shoot);
void frostbolt_dammage2(global_t *g, int n, int i);
void frostbolt_dammage(global_t *g, int n, int i);
spell_t init_blink(void);
void blink_func(void *tmp, int n);
void blink_update(void *tmp, int n);
spell_t init_shield(void);
void shield_func(void *tmp, int n);
void shield_update(void *tmp, int n);
void explosion_func(void *tmp, int n);
void explosion_func2(void *tmp, int n);
void explosion_func3(void *tmp, int n);
void explosion_func4(void *tmp, int n);
spell_t init_explosion(void);
spell_t init_explosion2(spell_t s);
spell_t init_explosion3(spell_t s);
spell_t init_explosion4(spell_t s);
void explosion_update(void *tmp, int n);
void explosion_update2(void *tmp, int n);
void explosion_update3(void *tmp, int n);
void explosion_update4(void *tmp, int n);
void update_explosion_particles(global_t *g, gameobject_t *p);
void update_explosion_particles2(global_t *g, gameobject_t *p);
void update_explosion_particles3(global_t *g, gameobject_t *p);
void update_explosion_particles4(global_t *g, gameobject_t *p, int i);
void explosion_dammage(global_t *g, int n);
void explosion_dammage2(global_t *g, int i);
void explosion_dammage3(global_t *g,  gameobject_t *p);
spell_t init_aoe(void);
spell_t init_aoe2(spell_t s);
void aoe_func(void *tmp, int n);
void aoe_update(void *tmp, int n);
void aoe_update2(global_t *g, gameobject_t *p);
void aoe_dammage2(global_t *g, int n);
spell_t init_fireball(void);
spell_t init_fireball2(spell_t s);
void fireball_func(void *tmp, int j);
void fireball_func2(void *tmp, int n);
void fireball_update(void *tmp, int n);
void fireball_dammage(global_t *g, int n, int i);
void fireball_particles(global_t *g, gameobject_t shoot);
void update_fireball_particles(global_t *g, gameobject_t shoot);
void update_fireball_particles2(global_t *g, gameobject_t shoot, int i);
void init_fireball_particles(global_t *g, gameobject_t shoot);
void init_sickle_particles(global_t *g, gameobject_t shoot);
void sickle_update(void *tmp, int n);
void sickle_dammage(global_t *g, int n, int i);
void sickle_particles(global_t *g, gameobject_t shoot);
void update_sickle_particles(global_t *g, gameobject_t shoot);
void update_sickle_particles2(global_t *g, gameobject_t shoot, int i);
spell_t init_sickle(void);
spell_t init_sickle2(spell_t s);
void sickle_func_boss(void *tmp, int j);
void sickle_func(void *tmp, int j);
void sickle_func2(void *tmp, int n);
void ring_func(void *tmp, int n);
void particles_effect_ring(global_t *g, int n);
void ring_update(void *tmp, int n);
void ring_dammage(global_t *g, int n);
void ring_update2(global_t *g, gameobject_t *p);
spell_t init_ring(void);
spell_t init_ring2(spell_t s);
spell_t init_zone(void);
spell_t init_zone2(spell_t s);
void zone_func_boss(void *tmp, int j);
void zone_func(void *tmp, int j);
void zone_func2(void *tmp, int n);
void zone_update(void *tmp, int n);
void zone_dammage(global_t *g, int n, int i);
void zone_particles(global_t *g, gameobject_t shoot);
void update_zone_particles(global_t *g, gameobject_t shoot);
void update_zone_particles2(global_t *g, gameobject_t shoot, int i);
void init_zone_particles(global_t *g, gameobject_t shoot);
void heal_func(void *tmp, int n);
void particles_effect_heal(global_t *g, int n);
void heal_update(void *tmp, int n);
spell_t init_heal(void);
spell_t init_heal2(spell_t s);

//////// QUEST ////////

text_info_t init_text_quest(int size, sfVector2f pos);
text_info_t init_header_quest(int size, sfVector2f pos);
text_info_t init_top_name_quest(int size, sfVector2f pos);
int length_of_word(text_info_t text, char *word);
void draw_text_in_box(text_info_t text, global_t *g, int *y);
void draw_quest(text_info_t header, text_info_t text, global_t *g, int i);
void update_quest_interface_ui(global_t *g);

//////// INVENTORY ////////

void drop_items(ennemi_t ennemi, global_t *g);
void give_player_item(item_t item, global_t *g);
void update_pos_item_in_inventory(global_t *g);
void draw_gold(global_t *g, sfVector2f pos, int gold);
void display_info_item(global_t *g);
item_t item_from_char(char *name, global_t *g);
int item_in_inventory(char *name, global_t *g);

/////// UI ////////

void update_spell_ui(global_t *g);
void update_inventory_interface_ui(global_t *g);
void update_quest_interface_ui(global_t *g);
void update_ui(global_t *g);
void update_map_ui(global_t *g);

//////// ENNEMI ////////

void init_ennemi(global_t *g);
void move_ennemi(global_t *g, int i);
void ennemi_attack(global_t *g, int i);
void ennemi_death(global_t *g, int i);
void update_ennemi(global_t *g);
void draw_life(ennemi_t g, sfRenderWindow *window, global_t *glo);
void draw_name(ennemi_t g, sfRenderWindow *window);
void draw_ennemi(global_t *g, int i);
global_t *init_ennemi2(global_t *g, int i);
void init_ennemi3(global_t *g);
global_t *init_wolf(global_t *g, int i);
global_t *init_mage(global_t *g, int i);
global_t *init_bunny(global_t *g, int i);
void respawn_ennemi(global_t *g, int i);
int inwall_ennemi(global_t *g, int i);

//////// FRAME ////////

void update_frame(global_t *g);
void update_frame_selection(global_t *g);
void ennemi_border(global_t *g, gameobject_t border[2], \
sfRectangleShape *hp, sfRectangleShape *mana);
void player_border(global_t *g, gameobject_t border[2], \
sfRectangleShape *hp, sfRectangleShape *mana);

//////// SAVE /////////

void update_save_back(global_t *g);
save_t *init_save(char *path, global_t *g);
void draw_preview(global_t *g);
void draw_text_preview(global_t *g);
void enter_name(global_t *g);
void print_new_save(global_t *g);

//////// TEXT MIDDLE ////////

text_info_t init_text_middle(int size);
void text_middle(global_t *g);
void message_middle(global_t *g, char *message);

//////// PNJ ////////

void init_pnj(global_t *g);
void update_pnj(global_t *g);

//////// VENDOR ////////

void update_vendor_interface_ui(global_t *g);

//////// MATH ////////

float square(float a);
float pythagore(float a, float b);

//////// BOSS ////////

void init_boss(global_t *g);
void update_boss(global_t *g);
void move_boss(global_t *g, int i);
void draw_boss(global_t *g, int i);
void draw_bname(boss_t g, sfRenderWindow *window, global_t *glo);
void draw_blife(boss_t g, sfRenderWindow *window, global_t *glo);
void boss_attack(global_t *g, int i);
void fireball_func_boss(void *tmp, int j);
void boss_phase1(global_t *g, int i);
void boss_phase2(global_t *g, int i);
void boss_phase3(global_t *g, int i);
void boss_phase4(global_t *g, int i);
void boss_animation(global_t *g, float angle);
void update_boss_phase2(global_t *g, int i, int j);
