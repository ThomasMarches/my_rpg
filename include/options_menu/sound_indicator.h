/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** sound_indicator
*/

#ifndef SOUND_INDICATOR_H_
#define SOUND_INDICATOR_H_

#include "my_game.h"
#include "my_json.h"

typedef struct {
    int volume_unit;
    int default_x;
    int bar_width;
} rpg_options_sound_indicator_t;

bool rpg_options_sound_indicator_create_extend_from_conf(game_object_t *,
json_object_t *);
bool rpg_options_update_sound_indicator(game_object_t *, scene_t *);

#endif /* !SOUND_INDICATOR_H_ */
