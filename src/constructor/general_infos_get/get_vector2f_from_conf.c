/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_pos_from_conf
*/

#include "my_json.h"
#include "my_game.h"

bool get_vector2f_from_conf(json_object_t *js, sfVector2f *pos, char *key)
{
    json_value_t *value = json_get_element_by_key(js, key);
    json_array_t *array = NULL;

    if (!value || value->value_type != ARRAY)
        return (false);
    array = value->value;
    for (int i = 0; array->array[i]; i++)
        if (array->array[i]->value_type != INT)
            return (false);
    if (array->elem_count == 2) {
        pos->x = *((int *)array->array[0]->value);
        pos->y = *((int *)array->array[1]->value);
        return (true);
    }
    return (false);
}