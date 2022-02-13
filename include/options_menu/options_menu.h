/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** options_menu
*/

#ifndef OPTIONS_MENU_H_
#define OPTIONS_MENU_H_

#include "my_game.h"

game_object_t *rpg_options_create_bar(game_object_t *, char *, sfVector2f);
game_object_t *rpg_options_create_indicator(game_object_t *, char *, \
sfVector2f);
game_object_t *rpg_options_create_object_list(void);
scene_t *rpg_options_create_scene(game_t *game);
void rpg_options_draw_scene(scene_t *scene, game_t *game, \
sfRenderWindow *window);

#endif /* !OPTIONS_MENU_H_ */
