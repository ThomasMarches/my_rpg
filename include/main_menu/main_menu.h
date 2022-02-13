/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_menu
*/

#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#include "my_game.h"

scene_t *rpg_main_menu_create_scene(game_t *game);
void rpg_main_menu_draw_scene(scene_t *scene, game_t *game, \
sfRenderWindow *window);
void rpg_main_menu_bind_event(scene_t *scene);
game_object_t *rpg_main_menu_create_buttons(void);

#endif /* !MAIN_MENU_H_ */
