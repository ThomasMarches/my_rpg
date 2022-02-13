/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_parse_get_value
*/

#include "my_json.h"
#include <stdlib.h>

static json_value_t json_parse_compute_value(char **buff)
{
    json_value_t value = {NONE, NULL};

    switch (**buff) {
        case '{':
            value.value = json_parse_object(buff);
            value.value_type = OBJECT;
            break;
        case '[':
            value.value = json_parse_array(buff);
            value.value_type = ARRAY;
            break;
        case '"':
            value.value = json_parse_get_string(buff);
            value.value_type = STRING;
            break;
        default:
            value = json_parse_get_int_value(buff);
    }
    return (value);
}

json_value_t json_parse_get_value(char **buff)
{
    json_value_t value = {NONE, NULL};

    value = json_parse_compute_value(buff);
    if (json_parse_check_next_chr(buff) == -1) {
        json_value_destroy(&value);
        return ((json_value_t) {NONE, NULL});
    }
    return (value);
}