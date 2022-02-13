/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_bool_from_conf
*/

#include "components/get_from_config.h"

bool get_bool_from_conf(json_object_t *js, bool *var, char *key)
{
    json_value_t *value = json_get_element_by_key(js, key);

    if (!value || value->value_type != BOOLEAN)
        return (false);
    *var = *((bool *)value->value);
    return (true);
}