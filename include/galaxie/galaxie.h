/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie
*/

#ifndef GALAXIE_H_
#define GALAXIE_H_

#include "my_game.h"

typedef enum {
    PLAYER,
    PLANET,
    MAX
} rpg_galaxie_z_index;

scene_t *rpg_galaxie_create_scene(game_t *game);
void rpg_galaxie_handle_event(scene_t *scene, game_t *game, \
sfRenderWindow *window);
void rpg_galaxie_draw_scene(scene_t *scene, game_t *game,
sfRenderWindow *window);
game_object_t *rpg_galaxie_create_ship(void);
game_object_t *rpg_galaxie_generate_space(void);
void rpg_galaxie_handle_key_pressed(sfEvent event, game_t *game, \
scene_t *scene, sfRenderWindow *window);
game_object_t *rpg_galaxie_move_on_map(scene_t *scene, sfVector2f move);

#endif /* !GALAXIE_H_ */
