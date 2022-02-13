/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_scene_z_index_deepth_from_config
*/

#include "my_game.h"
#include "my_json.h"
#include "my_rpg.h"

int load_scene_z_index_deepth_from_config(json_object_t *js)
{
    json_value_t *value = json_get_element_by_key(js, "z_index_deepth");
    int id = 0;

    if (!value || value->value_type != INT)
        return (-1);
    id = *((int *)value->value);
    if (id < 0)
        return (-1);
    return (id);
}