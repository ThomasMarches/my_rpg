/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_array_destroy
*/

#include "my_json.h"
#include <stdlib.h>

void json_array_destroy(json_array_t *array)
{
    int i = 0;

    if (array && array->array) {
        for (; array->array[i]; i++) {
            json_value_destroy(array->array[i]);
            free(array->array[i]);
        }
        free(array->array[i]);
        free(array->array);
    }
    if (array)
        free(array);
}