/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_indicator
*/

#include "my_game.h"
#include "options_menu/sound_indicator.h"

bool rpg_options_update_sound_indicator(game_object_t *object, scene_t *scene)
{
    rpg_options_sound_indicator_t *indicator = object->extend;
    int vol = sfListener_getGlobalVolume() / indicator->volume_unit;

    object->pos.x = (float)indicator->default_x + (indicator->bar_width /
    indicator->volume_unit) * (vol - 1);
    sfSprite_setPosition(object->sprite, object->pos);
    update_appearing_object(object, scene);
    return (true);
}