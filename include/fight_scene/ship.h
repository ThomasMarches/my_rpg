/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_function
*/

#ifndef SHIP_H_
#define SHIP_H_

#include "my_game.h"
#include "item/item_id.h"

typedef struct ship {
    bool in_fight;
    int hp;
    int max_hp;
    int shield;
    item_id equiped_weapon;
    int damage;
    int repair_value;
    int repair_statue;
    int dodge_value;
    int member_in_ship;
    int done_actions;
    sfText *hp_text;
    sfText *repair_turn_left;
    sfText *shield_text;
    sfText *action_left;
} space_ship_t;

void free_text(sfText *text);

#endif /* !SHIP_H_ */
