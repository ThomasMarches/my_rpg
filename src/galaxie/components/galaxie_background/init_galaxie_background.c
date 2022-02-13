/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_galaxie_background
*/

#include "galaxie/galaxie_minimap.h"

game_object_t *init_galaxie_background(game_object_t *object)
{
    galaxie_mini_map_t *map = object->extend;
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(
    map->scene->window));
    game_object_t *tmp = NULL;

    pos.x -= 1920 * 3.5;
    pos.y -= 1000 * 3.5;
    tmp = create_galaxie_background(object, map, pos);
    object = (tmp) ? tmp : object;
    return (object);
}