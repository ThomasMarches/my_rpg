/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_get_element_by_key
*/

#include "my_json.h"
#include <stdlib.h>
#include <stdbool.h>

static bool my_exactcmp(char *str1, char *str2)
{
    int i = 0;

    for (; str1[i] != '\0' && str2[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
    if (str1[i] != '\0')
        return (1);
    if (str2[i] != '\0')
        return (-1);
    return (0);
}

json_value_t *json_get_element_by_key(json_object_t *js, char *key)
{
    if (js->key && my_exactcmp(js->key, key) == 0)
        return (&js->value);
    for (json_object_t *next = js->next; next; next = next->next) {
        if (next->key && my_exactcmp(next->key, key) == 0)
            return (&next->value);
    }
    if (js->value.value_type == OBJECT)
        return (json_get_element_by_key(js->value.value, key));
    return (NULL);
}