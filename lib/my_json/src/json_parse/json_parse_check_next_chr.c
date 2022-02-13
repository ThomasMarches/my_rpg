/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_parse_check_next_chr
*/

#include "my_json.h"

int json_parse_check_next_chr(char **buff)
{
    if (**buff != ',' && **buff != ']' && **buff != '}')
        return (-1);
    if (**buff == ',')
        (*buff)++;
    return (0);
}