/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_parse_get_simple_value
*/

#include "my_json.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

static int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0' || i < n; i++) {
        if (s1[i] - s2[i] != 0) {
            return (s1[i] - s2[i]);
        }
        return (0);
    }
    return (0);
}

static json_value_t json_parse_get_bool_value(char **buff)
{
    json_value_t value = {NONE, NULL};
    bool *val = NULL;

    value.value = malloc(sizeof(bool));
    if (!value.value)
        return (value);
    value.value_type = BOOLEAN;
    val = value.value;
    if (my_strncmp(*buff, "true", 4) == 0) {
        *val = true;
        *buff += 4;
    }
    if (my_strncmp(*buff, "false", 5) == 0) {
        *val = false;
        *buff += 5;
    }
    return (value);
}

static json_value_t json_parse_get_float_value(char **buff, int i)
{
    json_value_t value = {FLOAT, NULL};
    float *val = malloc(sizeof(float));
    int first_part = 0;
    int second_part = 0;

    if (val == NULL)
        return (value);
    first_part = my_getnbr(*buff);
    second_part = my_getnbr(*buff + i + 1);
    *val += (first_part < 0) ? - second_part : second_part;
    for (; *val > 1;*val /= 10, i++);
    *val += first_part;
    *buff += i + 1;
    value.value = val;
    return (value);
}

json_value_t json_parse_get_int_value(char **buff)
{
    int *val = NULL;
    char *str_nbr = NULL;
    json_value_t value = {INT, NULL};
    int i = 0;

    if (my_strncmp(*buff, "true", 4) == 0 || my_strncmp(*buff, "false", 5) == 0)
        return (json_parse_get_bool_value(buff));
    else if (**buff == '-')
        i += 1;
    for (; *(*buff + i) <= '9' && *(*buff +i) >= '0'; i++);
    if (*(*buff + i) == '.')
        return (json_parse_get_float_value(buff, i));
    val = malloc(sizeof(int));
    if (val == NULL)
        return (value);
    *val = my_getnbr(*buff);
    *buff += i;
    value.value = val;
    return (value);
}