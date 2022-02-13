/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_sound_indicator_extend_from_conf
*/

#include "options_menu/sound_bar.h"
#include <stdlib.h>

bool rpg_options_sound_bar_create_extend_from_conf(game_object_t *object,
json_object_t *js)
{
    rpg_options_sound_bar_t *bar = malloc(sizeof(rpg_options_sound_bar_t));
    json_value_t *value = NULL;

    if (bar == NULL)
        return (false);
    value = json_get_element_by_key(js, "volume_unit");
    bar->volume_unit = (value && value->value_type == INT) ?
    *((int *) value->value): -1;
    value = json_get_element_by_key(js, "min_volume");
    bar->min_volume = (value && value->value_type == INT) ?
    *((int *) value->value): -1;
    value = json_get_element_by_key(js, "max_volume");
    bar->max_volume = (value && value->value_type == INT) ?
    *((int *) value->value): -1;
    bar->default_x = object->pos.x;
    if (bar->volume_unit < 0 || bar->min_volume < 0 || bar->max_volume < 0) {
        free(bar);
        return (false);
    }
    object->extend = bar;
    return (true);
}