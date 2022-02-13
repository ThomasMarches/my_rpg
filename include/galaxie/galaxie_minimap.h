/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_minimap
*/

#ifndef GALAXIE_MINIMAP_H_
#define GALAXIE_MINIMAP_H_

#include "my_game.h"
#include "my_json.h"

typedef struct {
    sfView *view;
    scene_t *scene;
    char *background_path;
} galaxie_mini_map_t;

void galaxie_mini_map_destroy(void *pt);
galaxie_mini_map_t *galaxie_minimap_create_extend(json_object_t *js,
game_t *game, scene_t *scene);
void draw_mini_map(sfRenderWindow *window, game_object_t *object);
bool galaxie_mini_map_update(game_object_t *object, scene_t *scene);
game_object_t *init_galaxie_background(game_object_t *object);
game_object_t *create_galaxie_background(game_object_t *last,
galaxie_mini_map_t *map, sfVector2f pos);

#endif /* !GALAXIE_MINIMAP_H_ */
