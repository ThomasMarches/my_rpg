/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_galaxie_mini_map
*/

#include "galaxie/galaxie_minimap.h"
#include <stdlib.h>

game_object_t *create_galaxie_mini_map(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = malloc(sizeof(game_object_t));

    if (object == NULL)
        return (NULL);
    init_game_object(object);
    object->z_index = scene->z_index_deepth;
    object->draw = &draw_mini_map;
    object->extend = galaxie_minimap_create_extend(js, game, scene);
    if (object->extend == NULL) {
        destroy_game_object(scene, object);
        return (NULL);
    }
    object->next = last;
    object->free_extend = &galaxie_mini_map_destroy;
    object = init_galaxie_background(object);
    return (object);
}