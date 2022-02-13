/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_parse_array
*/

#include "my_json.h"
#include <stdlib.h>

json_array_t *json_parse_array(char **buff)
{
    json_array_t *array = json_array_create();
    json_value_t *value = NULL;

    if (array == NULL)
        return (NULL);
    (*buff)++;
    while (**buff != ']' && **buff != '\0') {
        value = json_parse_value_array(buff);
        if (value == NULL)
            return (NULL);
        json_array_add_value(array, value);
    }
    if (**buff == '\0')
        return (NULL);
    (*buff)++;
    return (array);
}