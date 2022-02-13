/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_object_from_conf
*/

#include "my_game.h"
#include "my_json.h"
#include "my_rpg.h"
#include "components/constructors.h"

game_object_t *create_object_from_config(json_object_t *js, \
game_object_t *next, game_t *game, scene_t *scene)
{
    json_value_t *value = json_get_element_by_key(js, "type");
    int constructor_id = 0;

    if (!value || value->value_type != INT)
        return (NULL);
    constructor_id = *((int *) value->value);
    if (constructor_id < 0 || constructor_id >= CONSTRUCTORS_MAX_ID)
        return (NULL);
    return ((game_object_t *) \
    CONSTRUCTORS[constructor_id](next, js, game, scene));
}