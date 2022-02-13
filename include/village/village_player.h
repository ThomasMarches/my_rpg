/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** village_player
*/

#ifndef VILLAGE_PLAYER_H_
#define VILLAGE_PLAYER_H_

#include "my_game.h"

enum {
    PLAYER_DOWN,
    PLAYER_UP,
    PLAYER_LEFT,
    PLAYER_RIGHT
};

static const int SPEED = 5;

bool update_player(game_object_t *object, scene_t *scene);

#endif /* !VILLAGE_PLAYER_H_ */
