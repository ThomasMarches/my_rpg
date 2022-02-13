/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** decor_constructor
*/

#ifndef DECOR_CONSTRUCTOR_H_
#define DECOR_CONSTRUCTOR_H_

#include "my_game.h"
#include "my_json.h"

game_object_t *create_object_from_config(json_object_t *, game_object_t *, \
game_t *, scene_t *);

#endif /* !DECOR_CONSTRUCTOR_H_ */
