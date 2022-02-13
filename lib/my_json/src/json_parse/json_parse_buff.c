/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_parse_buff
*/

#include "my_json.h"
#include <stdlib.h>

int json_parse_buff(char *buff, json_object_t *js)
{
    if (*buff == '[') {
        js->value.value = json_parse_array(&buff);
        js->value.value_type = ARRAY;
    } else if (*buff == '{') {
        js->value.value = json_parse_object(&buff);
        js->value.value_type = OBJECT;
    } else
        return (-1);
    if (js->value.value == NULL)
        return (-1);
    return (0);
}