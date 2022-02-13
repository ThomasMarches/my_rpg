/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_create
*/

#include "my_json.h"
#include <stdlib.h>

json_object_t *json_object_create(void)
{
    json_object_t *js = malloc(sizeof(json_object_t));

    if (!js)
        return (NULL);
    js->key = NULL;
    js->next = NULL;
    js->value = (json_value_t) {NONE, NULL};
    return (js);
}