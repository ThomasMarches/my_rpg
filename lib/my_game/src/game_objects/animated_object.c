/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** animated_object
*/

#include "my_game.h"
#include <stdlib.h>

bool update_animated_object(game_object_t *object, scene_t *scene)
{
    update_game_object_frame(object);
    return (true);
}

game_object_t *create_animated_object(game_object_t *last, char *path, \
sfVector2f pos, sfIntRect **frame_keys)
{
    game_object_t *object = create_game_object(last, path, pos, EFFECT);

    if (object == NULL)
        return (NULL);
    object->anim = malloc(sizeof(anim_t) * 1);
    if (object->anim == NULL)
        return (NULL);
    object->anim[0].frames_key = frame_keys;
    object->anim[0].loop = false;
    object->anim[0].frame_id = 0;
    for (int i = 0; object->anim[0].frames_key[i] != NULL; i++)
        object->anim[0].restart_id = i;
    object->state = 0;
    object->type = DECOR;
    object->update = &update_animated_object;
    init_game_object_frame(object);
    return (object);
}