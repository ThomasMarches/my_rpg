/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_button_from_conf
*/

#include "my_json.h"
#include "my_game.h"
#include "components/get_from_config.h"
#include "components/button/button.h"
#include <stdlib.h>

static bool rpg_create_animated_button_anim(game_object_t *object,
sfIntRect **frame_keys, char *sound_path, json_object_t *js)
{
    object->anim = malloc(sizeof(anim_t) * 3);
    if (object->anim == NULL)
        return (false);
    object->anim[2] = (anim_t) {NULL, NULL, false, true, 0, 0};
    for (int i = 0; i < 2; i++)
        object->anim[i] = (anim_t) {frame_keys, NULL, false, true, 0, 2};
    object->anim[SELECTED].sound_buffer =
    sfSoundBuffer_createFromFile(sound_path);
    object->anim[SELECTED].frames_key =
    get_frame_keys_from_conf(js, "frame_keys");
    if (object->anim[SELECTED].sound_buffer == NULL ||
    object->anim[SELECTED].frames_key == NULL)
        return (false);
    return (true);
}

static bool rpg_anim_button(json_object_t *js, game_object_t *object,
scene_t *scene)
{
    sfIntRect **frame_keys = get_frame_keys_from_conf(js, "frame_keys");
    char *sound_path = get_str_from_conf(js, "sound_path");

    if (frame_keys == NULL || sound_path == NULL) {
        destroy_game_object(scene, object);
        return (false);
    }
    object->state = UNSELECTED;
    if (!rpg_create_animated_button_anim(object, frame_keys, sound_path, js)) {
        destroy_game_object(scene, object);
        return (false);
    }
    return (true);
}

game_object_t *rpg_create_animated_button_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = NULL;

    object = rpg_create_button_from_conf(last, js, game, scene);
    if (object == NULL)
        return (NULL);
    object->update = &rpg_update_animated_button;
    object->sound_effect = sfSound_create();
    if (!rpg_anim_button(js, object, scene) || object->sound_effect == NULL) {
        destroy_game_object(scene, object);
        return (NULL);
    }
    object->state = UNSELECTED;
    object->anim[object->state].frame_id = \
    object->anim[object->state].restart_id;
    init_appearing_object(object);
    init_game_object_frame(object);
    return (object);
}