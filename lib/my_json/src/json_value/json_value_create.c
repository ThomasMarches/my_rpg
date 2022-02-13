/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_value_create
*/

#include "my_json.h"
#include <stdlib.h>

json_value_t *json_value_create(void)
{
    json_value_t *value = malloc(sizeof(json_value_t));

    if (value == NULL)
        return (NULL);
    value->value_type = NONE;
    value->value = NULL;
    return (value);
}