/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_object_destroy_value
*/

#include "my_json.h"
#include <stdlib.h>

void json_value_destroy(json_value_t *js)
{
    if (js->value_type == BOOLEAN || js->value_type == INT || \
    js->value_type == STRING)
        free(js->value);
    else if (js->value_type == ARRAY)
        json_array_destroy(js->value);
    if (js->value_type == OBJECT)
        json_object_destroy(js->value);
}