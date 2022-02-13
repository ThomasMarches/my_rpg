/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_str_from_conf
*/

#include "my_json.h"
#include <stdlib.h>

char *get_str_from_conf(json_object_t *js, char *key)
{
    json_value_t *value = json_get_element_by_key(js, key);
    char *str = NULL;

    if (value && value->value_type == STRING)
        str = value->value;
    return (str);
}