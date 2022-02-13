/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_scene_fp
*/

#ifndef DRAW_SCENE_FP_H_
#define DRAW_SCENE_FP_H_

#include "my_game.h"

enum {
    MAIN_MENU_DRAW_ID,
    MAX_DRAW_SCENE_ID
};

void rpg_main_menu_draw_scene(scene_t *scene, game_t *game, sfRenderWindow
*window);

static void (*DRAW_SCENE_FP[])(scene_t *, game_t *, sfRenderWindow *) = {
    &rpg_main_menu_draw_scene
};

#endif /* !DRAW_SCENE_FP_H_ */
