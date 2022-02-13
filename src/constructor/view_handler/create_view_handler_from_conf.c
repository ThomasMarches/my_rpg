/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_view_handler_from_conf
*/

#include "components/view_handler/view_handler.h"
#include "components/get_from_config.h"
#include <stdlib.h>

game_object_t *create_view_handler_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = NULL;

    object = malloc(sizeof(game_object_t));
    if (object == NULL)
        return (NULL);
    init_game_object(object);
    object->extend = create_view_handler_extend_from_conf(js);
    object->free_extend = &free;
    object->update = &view_handler_update;
    object->draw = NULL;
    return (object);
}