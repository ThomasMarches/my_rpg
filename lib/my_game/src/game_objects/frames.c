/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** frames
*/

#include "my_game.h"

void update_sound_effect(game_object_t *game_object, int state)
{
    if (game_object->sound_effect != NULL) {
        if (game_object->anim->sound_loop == true)
            sfSound_setLoop(game_object->sound_effect, sfTrue);
        else
            sfSound_setLoop(game_object->sound_effect, sfFalse);
        if (game_object->anim[state].sound_buffer != NULL) {
            sfSound_setBuffer(game_object->sound_effect, \
            game_object->anim[state].sound_buffer);
            sfSound_play(game_object->sound_effect);
        } else
            sfSound_stop(game_object->sound_effect);
    }
}

void init_game_object_frame(game_object_t *game_object)
{
    int state = game_object->state;
    anim_t *anim = game_object->anim;

    update_sound_effect(game_object, state);
    sfSprite_setTextureRect(game_object->sprite, \
    *anim[state].frames_key[anim[state].frame_id]);
    game_object->box = *anim[state].frames_key[anim[state].frame_id];
    game_object->box.top = game_object->pos.y;
    game_object->box.left = game_object->pos.x;
}

void update_game_object_state(game_object_t *game_object, int state)
{
    anim_t *anim = game_object->anim;

    if (anim == NULL)
        return;
    update_sound_effect(game_object, state);
    game_object->state = state;
    anim[state].frame_id = 0;
    sfSprite_setTextureRect(game_object->sprite, \
    *anim[state].frames_key[anim[state].frame_id]);
    game_object->box = *anim[state].frames_key[anim[state].frame_id];
    game_object->box.top = game_object->pos.y;
    game_object->box.left = game_object->pos.x;
}

void update_game_object_frame_reversed(game_object_t *game_object)
{
    int state = game_object->state;
    anim_t *anim = game_object->anim;

    anim[state].frame_id -= 1;
    if (anim[state].frame_id < 0) {
        if (anim[state].loop == true)
            anim[state].frame_id = anim[state].restart_id;
        else
            anim[state].frame_id += 1;
    }
    sfSprite_setTextureRect(game_object->sprite, \
    *anim[state].frames_key[anim[state].frame_id]);
    game_object->box = *anim[state].frames_key[anim[state].frame_id];
    game_object->box.top = game_object->pos.y;
    game_object->box.left = game_object->pos.x;
}

void update_game_object_frame(game_object_t *game_object)
{
    int state = game_object->state;
    anim_t *anim = game_object->anim;

    anim[state].frame_id += 1;
    if (anim[state].frames_key[anim[state].frame_id] == NULL) {
        if (anim[state].loop == true)
            anim[state].frame_id = anim[state].restart_id;
        else
            anim[state].frame_id -= 1;
    }
    sfSprite_setTextureRect(game_object->sprite, \
    *anim[state].frames_key[anim[state].frame_id]);
    game_object->box = *anim[state].frames_key[anim[state].frame_id];
    game_object->box.top = game_object->pos.y;
    game_object->box.left = game_object->pos.x;
}