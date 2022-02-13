/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_parse_value_array
*/

#include "my_json.h"
#include <stdlib.h>

json_value_t *json_parse_value_array(char **buff)
{
    json_value_t *value = json_value_create();

    if (value == NULL)
        return (NULL);
    *value = json_parse_get_value(buff);
    if (value->value == NULL) {
        free(value);
        return (NULL);
    }
    return (value);
}