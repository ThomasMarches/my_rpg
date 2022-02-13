/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** infos_menu
*/

#ifndef INFOS_MENU_H_
#define INFOS_MENU_H_

#include "my_game.h"

scene_t *rpg_infos_create_scene(game_t *game);
scene_t *rpg_infos_draw_scene(scene_t *scene, game_t *game, \
sfRenderWindow *window);

#endif /* !INFOS_MENU_H_ */