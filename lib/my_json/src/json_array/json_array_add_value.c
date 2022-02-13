/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_array_add_value
*/

#include "my_json.h"
#include <stdlib.h>

void json_array_add_value(json_array_t *array, json_value_t *value)
{
    json_value_t **new_array = malloc(sizeof(json_value_t) *
    (array->elem_count + 2));

    if (new_array == NULL)
        return;
    for (int i = 0; array->array[i]; i++) {
        new_array[i] = array->array[i];
    }
    new_array[array->elem_count] = value;
    array->elem_count += 1;
    new_array[array->elem_count] = NULL;
    free(array->array);
    array->array = new_array;
}