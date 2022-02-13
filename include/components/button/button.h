/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** animated_button
*/

#ifndef ANIMATED_BUTTON_H_
#define ANIMATED_BUTTON_H_

#include "my_game.h"
#include "my_json.h"

bool rpg_update_animated_button(game_object_t *, scene_t *);
game_object_t *rpg_create_button_from_conf(game_object_t *,
json_object_t *, game_t *, scene_t *);

#endif /* !ANIMATED_BUTTON_H_ */
