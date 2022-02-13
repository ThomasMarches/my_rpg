/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_sound_indicator_extend_from_conf
*/

#include "options_menu/sound_indicator.h"
#include <stdlib.h>

bool rpg_options_sound_indicator_create_extend_from_conf(game_object_t *object,
json_object_t *js)
{
    rpg_options_sound_indicator_t *indicator =
    malloc(sizeof(rpg_options_sound_indicator_t));
    json_value_t *value = NULL;

    if (indicator == NULL)
        return (false);
    value = json_get_element_by_key(js, "volume_unit");
    indicator->volume_unit = (value && value->value_type == INT) ?
    *((int *) value->value): -1;
    value = json_get_element_by_key(js, "bar_width");
    indicator->bar_width = (value && value->value_type == INT) ?
    *((int *) value->value): -1;
    indicator->default_x = object->pos.x;
    if (indicator->volume_unit < 0 || indicator->bar_width < 0) {
        free(indicator);
        return (false);
    }
    object->extend = indicator;
    object->free_extend = &free;
    return (true);
}