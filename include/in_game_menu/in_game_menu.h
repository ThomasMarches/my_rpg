/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** in_game_menu
*/

#ifndef IN_GAME_MENU_H_
#define IN_GAME_MENU_H_

#include "my_game.h"

int rpg_in_game_menu_loop(game_t *game, sfRenderWindow *window, \
scene_t *last_scene);
scene_t *rpg_in_game_menu_create_scene(game_t *game);
void rpg_in_game_menu_draw_pause_text(sfRenderWindow *window);
void rpg_in_game_menu_close_scene(scene_t *scene, sfRenderWindow *window, \
scene_t *last, game_t *game);
int rpg_in_game_menu_launch(game_t *game, scene_t *scene);

#endif /* !IN_GAME_MENU_H_ */
