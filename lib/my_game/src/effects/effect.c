/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** effect
*/

#include "my_game.h"
#include <stdlib.h>

bool update_effect(game_object_t *object, scene_t *scene)
{
    int frame_id = object->anim[object->state].frame_id + 1;

    update_game_object_frame(object);
    if (object->anim[object->state].frames_key[frame_id] == NULL)
        return (false);
    return (true);
}

game_object_t *create_effect(game_object_t *last, char *path, sfVector2f pos, \
sfIntRect **frame_keys)
{
    game_object_t *object = create_game_object(last, path, pos, EFFECT);

    object->anim = malloc(sizeof(anim_t) * 1);
    object->anim[0].frames_key = frame_keys;
    object->anim[0].loop = false;
    object->anim[0].frame_id = 0;
    object->anim[0].restart_id = 0;
    object->state = 0;
    object->update = &update_effect;
    init_game_object_frame(object);
    return (object);
}