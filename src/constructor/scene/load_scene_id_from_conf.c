/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_scene_from_conf_part2
*/

#include "my_game.h"
#include "my_json.h"
#include "my_rpg.h"

int load_scene_id_from_config(json_object_t *js)
{
    json_value_t *value = json_get_element_by_key(js, "id");
    int id = 0;

    if (!value || value->value_type != INT)
        return (-1);
    id = *((int *)value->value);
    if (id < 0 || id >= NULL_SCENE)
        return (-1);
    return (id);
}

