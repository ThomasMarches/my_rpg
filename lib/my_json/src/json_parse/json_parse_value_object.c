/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_parse_value_object
*/

#include "my_json.h"
#include <stdlib.h>

static char *json_parse_get_key_of_value(char **buff)
{
    int i = 0;
    char *key = NULL;

    if (**buff != '"')
        return (NULL);
    (*buff)++;
    for (; (*buff)[i] != '"' && (*buff)[i] != '\0'; i++);
    if ((*buff)[i] == '\0')
        return (NULL);
    key = my_strndup(*buff, i);
    *buff += i + 1;
    return (key);
}

void json_parse_value_object(char **buff, json_object_t *object)
{
    object->key = json_parse_get_key_of_value(buff);
    if (object->key == NULL)
        return;
    if (**buff != ':' || **buff == '\0')
        return;
    (*buff)++;
    object->value = json_parse_get_value(buff);
}