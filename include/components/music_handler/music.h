/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** music
*/

#ifndef MUSIC_H_
#define MUSIC_H_

#include "my_game.h"
#include <stdbool.h>

typedef struct music_handler {
    sfMusic *music;
    int volume;
    bool playing;
    bool loop;
} music_handler_t;

void rpg_music_handler_destroy_music(void *pt);
bool rpg_music_handler_play_music(game_object_t *object, scene_t *scene);

#endif /* !MUSIC_H_ */