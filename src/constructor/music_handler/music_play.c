/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** music_play.c
*/

#include "my_game.h"
#include "components/music_handler/music.h"
#include <stdio.h>
#include <unistd.h>
#include "SFML/Audio.h"

bool rpg_music_handler_play_music(game_object_t *object, scene_t *scene)
{
    music_handler_t *music = (music_handler_t *) object->extend;

    if (music == NULL || music->playing == 1)
        return (true);
    sfMusic_setVolume(music->music, music->volume);
    if (music->loop == 1)
        sfMusic_setLoop(music->music, sfTrue);
    sfMusic_play(music->music);
    music->playing = 1;
    return (true);
}