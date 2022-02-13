/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_function
*/


#ifndef ENNEMY_H_
#define ENNEMY_H_

#include "components/quest/quest.h"
#include "my_game.h"
#include "item/item_id.h"
#include "fight_scene/fight_handler.h"

typedef struct ennemy {
    char *name;
    int hp;
    int max_hp;
    int shield;
    int action_number;
    int dodge_value;
    int repair_value;
    item_id equiped_weapon;
    int damage;
    bool in_fight;
    action_id *id;
    int repair_statue;
    quest_id quest_id;
    sfText *name_text;
    sfText *hp_text;
    sfText *shield_text;
} ennemy_t;

void rpg_ennemy_draw(sfRenderWindow *window, game_object_t *object);
bool rpg_ennemy_update(game_object_t *object, scene_t *scene);
void rpg_ennemy_destroy(void *ptr);

#endif /* !ENNEMY_H_ */
