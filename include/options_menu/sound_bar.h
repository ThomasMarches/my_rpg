/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** sound_bar
*/

#ifndef SOUND_BAR_H_
#define SOUND_BAR_H_

#include "my_game.h"
#include "my_json.h"

typedef struct {
    int default_x;
    int min_volume;
    int max_volume;
    int volume_unit;
} rpg_options_sound_bar_t;

bool rpg_options_sound_bar_update(game_object_t *, scene_t *);
bool rpg_options_sound_bar_callback(game_object_t *, void *);
bool rpg_options_sound_bar_create_extend_from_conf(game_object_t *,
json_object_t *);

#endif /* !SOUND_BAR_H_ */
