/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_scene_background_color_from_config
*/

#include "my_game.h"
#include "my_json.h"
#include "my_rpg.h"

bool load_scene_background_color_from_config(json_object_t *js, scene_t *scene)
{
    json_value_t *value = json_get_element_by_key(js, "background_color");
    json_array_t *array = NULL;

    if (!value || value->value_type != ARRAY)
        return (false);
    array = value->value;
    if (!array || array->elem_count != 4)
        return (false);
    for (int i = 0; array->array[i]; i++)
        if (array->array[i]->value_type != INT)
            return (false);
    scene->background_color.r = *((int *) (array->array[0]->value));
    scene->background_color.g = *((int *) (array->array[1]->value));
    scene->background_color.b = *((int *) (array->array[2]->value));
    scene->background_color.a = *((int *) (array->array[3]->value));
    return (true);
}