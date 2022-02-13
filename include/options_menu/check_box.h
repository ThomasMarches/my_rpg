/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** check_box
*/

#ifndef CHECK_BOX_H_
#define CHECK_BOX_H_

#include "my_json.h"
#include "my_game.h"

enum {
    OFF,
    ON
};

bool rpg_check_box_update(game_object_t *, scene_t *);
bool rpg_check_box_callback(game_object_t *, void *);

#endif /* !CHECK_BOX_H_ */
