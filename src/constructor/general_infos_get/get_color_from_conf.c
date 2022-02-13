/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_color_from_conf
*/

#include "components/get_from_config.h"

bool get_color_from_conf(json_object_t *js, sfColor *color, char *key)
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
    color->r = *((int *) (array->array[0]->value));
    color->g = *((int *) (array->array[1]->value));
    color->b = *((int *) (array->array[2]->value));
    color->a = *((int *) (array->array[3]->value));
    return (true);
}