/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_music.c
*/

#include "my_game.h"
#include "my_json.h"
#include <stdlib.h>
#include "components/get_from_config.h"
#include "components/music_handler/music.h"
#include "SFML/Audio.h"

static music_handler_t *rpg_music_handler_create_extend_from_conf( \
game_object_t *object, json_object_t *js, game_t *game, scene_t *scene)
{
    music_handler_t *music_handler = malloc(sizeof(music_handler_t));

    if (music_handler == NULL)
        return (NULL);
    if ((music_handler->music = sfMusic_createFromFile(get_str_from_conf(js, \
    "sound_path"))) == NULL) {
        free(music_handler);
        return (NULL);
    }
    if (!get_bool_from_conf(js, (bool *) &music_handler->loop, "loop") || \
    !get_int_from_conf(js, &music_handler->volume, "volume")) {
        sfMusic_destroy(music_handler->music);
        free(music_handler);
        return (NULL);
    }
    music_handler->playing = 0;
    return (music_handler);
}

game_object_t *rpg_music_handler_create_from_conf(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = malloc(sizeof(game_object_t));

    if (object == NULL)
        return (NULL);
    init_game_object(object);
    object->type = MUSIC;
    object->next = last;
    object->draw = NULL;
    object->update = &rpg_music_handler_play_music;
    object->extend = (void *) \
    rpg_music_handler_create_extend_from_conf(object, js, game, scene);
    object->free_extend = &rpg_music_handler_destroy_music;
    if (object->extend == NULL) {
        free(object);
        return (NULL);
    }
    return (object);
}