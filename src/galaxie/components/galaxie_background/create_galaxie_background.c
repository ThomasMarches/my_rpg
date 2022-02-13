/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_galaxie_background
*/

#include "galaxie/galaxie_background.h"
#include "galaxie/galaxie_minimap.h"

game_object_t *create_galaxie_background(game_object_t *last,
galaxie_mini_map_t *map, sfVector2f pos)
{
    game_object_t *object = create_game_object(last, map->background_path, pos,
    GALAXIE_BACKGROUND);

    if (object == NULL)
        return (NULL);
    object->extend = map;
    object->update = &galaxie_background_update;
    return (object);
}