/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_frame_keys_from_conf
*/

#include <stdlib.h>
#include "my_game.h"
#include "my_json.h"
#include "components/get_from_config.h"

static bool get_frame_key_from_conf(json_array_t *array,
sfIntRect **frame_keys, int i)
{
    frame_keys[i] = malloc(sizeof(sfIntRect));
    if (frame_keys[i] == NULL)
        return (false);
    for (int i = 0; array->array[i]; i++)
        if (array->array[i]->value_type != INT)
            return (false);
    if (array->elem_count == 4) {
        frame_keys[i]->left = *((int *)array->array[0]->value);
        frame_keys[i]->top = *((int *)array->array[1]->value);
        frame_keys[i]->width = *((int *)array->array[2]->value);
        frame_keys[i]->height = *((int *)array->array[3]->value);
        return (true);
    }
    return (false);
}

sfIntRect **get_frame_keys_from_conf(json_object_t *js, char *key)
{
    sfIntRect **frame_keys = NULL;
    json_value_t *value = json_get_element_by_key(js, key);
    json_array_t *array = NULL;

    if (!value || value->value_type != ARRAY)
        return (NULL);
    array = value->value;
    for (int i = 0; array->array[i]; i++)
        if (array->array[i]->value_type != ARRAY)
            return (NULL);
    frame_keys = malloc(sizeof(sfIntRect *) * (array->elem_count + 1));
    if (frame_keys == NULL)
        return (NULL);
    for (int i = 0; array->array[i]; i++) {
        if (!get_frame_key_from_conf(array->array[i]->value, frame_keys, i))
            return (NULL);
    }
    frame_keys[array->elem_count] = NULL;
    return (frame_keys);
}