/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_object_destroy
*/

#include "my_json.h"
#include <stdlib.h>

void json_object_destroy(json_object_t *js)
{
    if (!js)
        return;
    json_value_destroy(&js->value);
    if (js->key)
        free(js->key);
    if (js->next)
        json_object_destroy(js->next);
    free(js);
}