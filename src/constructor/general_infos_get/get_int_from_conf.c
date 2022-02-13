/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_int_from_conf
*/

#include "my_json.h"
#include <stdbool.h>

bool get_int_from_conf(json_object_t *js, int *var, char *key)
{
    json_value_t *value = json_get_element_by_key(js, key);

    if (!value || value->value_type != INT)
        return (false);
    *var = *((int *)value->value);
    return (true);
}