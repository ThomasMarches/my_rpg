/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_parse_get_string
*/

#include "my_json.h"
#include <stdlib.h>
#include <string.h>

char *json_parse_get_string(char **buff)
{
    char *str = NULL;
    int i = 0;

    (*buff)++;
    for (; (*buff)[i] != '"' && (*buff)[i] != '\0'; i++);
    if ((*buff)[i] == '\0')
        return (NULL);
    str = my_strndup(*buff, i);
    *buff += i + 1;
    return (str);
}