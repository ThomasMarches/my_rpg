/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_scene_from_conf
*/

#include "my_game.h"
#include "my_json.h"
#include "my_rpg.h"
#include "components/scene/scene_constructor.h"

game_object_t *load_scene_objects_list_from_config(json_object_t *js,
game_t *game, scene_t *scene)
{
    json_value_t *value = NULL;
    json_array_t *array = NULL;
    game_object_t *list = NULL;
    game_object_t *tmp = NULL;

    value = json_get_element_by_key(js, "objects_list");
    if (!value || value->value_type != ARRAY)
        return (NULL);
    array = value->value;
    for (int i = 0; array->array[i]; i++) {
        if (array->array[i]->value_type != OBJECT)
            continue;
        value = json_get_element_by_key(array->array[i]->value, "type");
        if (value && value->value_type == INT) {
            tmp = create_object_from_config(array->array[i]->value, list, \
            game, scene);
            list = (tmp) ? tmp : list;
        }
    }
    return (list);
}