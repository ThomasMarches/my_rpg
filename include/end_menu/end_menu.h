/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** end_menu
*/

#ifndef END_MENU_H_
#define END_MENU_H_

#include "my_game.h"

scene_t *rpg_end_menu_create_scene(game_t *game);
void rpg_end_menu_draw_scene(scene_t *, game_t *, sfRenderWindow *);

#endif /* !END_MENU_H_ */