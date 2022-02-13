/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_scene_fp
*/

#ifndef UPDATE_SCENE_FP_H_
#define UPDATE_SCENE_FP_H_

#include "my_game.h"

enum {
    GENERAL_SCENE_UPDATE_ID,
    MAX_SCENE_UPDATE_ID
};

static void (*UPDATE_SCENE_FP[])(scene_t *, game_t *) = {
    &update_scene
};

#endif /* !UPDATE_SCENE_FP_H_ */
