/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** general_constructor
*/

#ifndef GENERAL_CONSTRUCTOR_H_
#define GENERAL_CONSTRUCTOR_H_

#include "my_game.h"
#include "my_json.h"

game_object_t *create_object_from_config(json_object_t *, game_object_t *,
game_t *, scene_t *);
game_object_t *load_scene_objects_list_from_config(json_object_t *,
game_t *, scene_t *);
int load_scene_id_from_config(json_object_t *);
int load_scene_z_index_deepth_from_config(json_object_t *);
void load_scene_draw_from_config(json_object_t *, scene_t *);
void load_scene_update_from_config(json_object_t *, scene_t *);
bool load_scene_background_color_from_config(json_object_t *, scene_t *);
bool load_scene_event_from_config(json_object_t *, scene_t *);

#endif /* !GENERAL_CONSTRUCTOR_H_ */
