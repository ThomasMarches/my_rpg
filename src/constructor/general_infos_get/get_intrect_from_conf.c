/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_box_from_conf
*/

#include "my_game.h"
#include "my_json.h"

bool get_intrect_from_conf(json_object_t *js, sfIntRect *rect, char *key)
{
    json_value_t *value = json_get_element_by_key(js, key);
    json_array_t *array = NULL;

    *rect = (sfIntRect) {0, 0, 0, 0};
    if (!value || value->value_type != ARRAY)
        return (false);
    array = value->value;
    for (int i = 0; array->array[i]; i++)
        if (array->array[i]->value_type != INT)
            return (false);
    if (array->elem_count == 4) {
        rect->left = *((int *)array->array[0]->value);
        rect->top = *((int *)array->array[1]->value);
        rect->width = *((int *)array->array[2]->value);
        rect->height = *((int *)array->array[3]->value);
        return (true);
    }
    return (false);
}