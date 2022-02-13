/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_array_create
*/

#include "my_json.h"
#include <stdlib.h>

json_array_t *json_array_create(void)
{
    json_array_t *array = malloc(sizeof(json_array_t));

    array->elem_count = 0;
    array->array = malloc(sizeof(json_value_t *));
    if (array->array == NULL) {
        json_array_destroy(array);
        return (NULL);
    }
    array->array[0] = NULL;
    return (array);
}