/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** parallax
*/

#include "my_game.h"
#include "item/item_id.h"
#include "fight_scene/ship.h"

#ifndef FIGHT_HANDLER_H_
#define FIGHT_HANDLER_H_

typedef struct ennemy ennemy_t;

typedef enum {
    ATTACK,
    DODGE,
    REPAIR,
    EMPTY
} action_id;

typedef struct fight_handler {
    bool in_fight;
    bool player_turn;
    int action_number;
    action_id *id;
    game_object_t *button;
    int done;
    sfText *fight_log[5];
} fight_handler_t;


void free_text(sfText *text);

// FIGHT LOG

void rpg_fight_log_destroy(fight_handler_t *handler);
void rpg_fight_log_push_text(fight_handler_t *handler, char *string, \
int number);
int rpg_fight_log_init(fight_handler_t *handler);


//SPACESHIP

void rpg_space_ship_destroy_tmp_text(char *tmp1, char *tmp2, char *tmp3);
item_id rpg_spaceship_get_equiped_weapon(game_object_t *object, \
scene_t *scene);
int rpg_spaceship_get_equip_size(game_object_t *object, scene_t *scene);
int rpg_spaceship_get_damage(game_object_t *object, scene_t *scene);
void rpg_fight_handler_remove_spaceship_life(game_object_t *object, \
scene_t *scene);
int rpg_spaceship_get_repair_value(game_object_t *object, scene_t *scene);
int rpg_spaceship_get_dodge_value(game_object_t *object, scene_t *scene);
void rpg_space_ship_destroy(void *ptr);
void rpg_fight_handler_handle_dodge_spaceship(game_object_t \
*object, int dodge, scene_t *scene);
void rpg_fight_handler_repair_spaceship(game_object_t *object, scene_t *scene);
int rpg_fight_handler_spaceship_get_repair_statue(scene_t *scene);
space_ship_t *rpg_spaceship_get_extend(scene_t *scene);
void rpg_space_ship_draw(sfRenderWindow *window, game_object_t *object);
bool rpg_spaceship_update(game_object_t *object, scene_t *scene);

//FIGHT HANDLER


bool rpg_fight_handler_callback(game_object_t *object, void *pt);
int rpg_fight_handler_get_player_action(game_object_t *object, \
scene_t *scene, int done);
int rpg_fight_handler_make_player_actions(game_object_t *object, \
scene_t *scene);
void rpg_fight_handler_free_extend(void *ptr);
void rpg_fight_handler_draw(sfRenderWindow *window, game_object_t *object);
bool rpg_fight_handler_update(game_object_t *object, scene_t *scene);
int rpg_fight_handler_dodge_handle(scene_t *scene, int number, int player);
fight_handler_t *rpg_fight_handler_get_extend(scene_t *scene);
int rpg_get_left_actions(scene_t *scene);


//ENNEMY


void rpg_fight_handler_remove_ennemy_life(game_object_t *object, \
scene_t *scene);
int rpg_ennemy_get_damage(game_object_t *object, scene_t *scene);
item_id rpg_ennemy_get_equiped_weapon(game_object_t *object, scene_t *scene);
void rpg_fight_handler_repair_ennemy(game_object_t *object, scene_t *scene);
void rpg_fight_handler_make_ennemy_play(game_object_t *object, scene_t *scene);
int rpg_ennemy_get_dodge_value(game_object_t *object, scene_t *scene);
struct ennemy *rpg_ennemy_get_extend(scene_t *scene);

#endif /* !FIGHT_HANDLER_H_ */