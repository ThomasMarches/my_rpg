/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_animated_button
*/

#include "my_game.h"

static void rpg_update_animated_button_rect(game_object_t *game_object, int id)
{
    int state = game_object->state;
    anim_t *anim = game_object->anim;

    sfSprite_setTextureRect(game_object->sprite, \
    *anim[state].frames_key[id]);
    game_object->box = *anim[state].frames_key[id];
    game_object->box.top = game_object->pos.y;
    game_object->box.left = game_object->pos.x;
}

bool rpg_update_animated_button(game_object_t *button, scene_t *scene)
{
    sfVector2f pos = get_mouse_exact_pos(scene->window);

    if (sfIntRect_contains(&button->box, pos.x, pos.y) && \
    button->state != SELECTED)
        rpg_update_animated_button_rect(button, 0);
    else if (!sfIntRect_contains(&button->box, pos.x, pos.y) && \
    button->state != UNSELECTED)
        rpg_update_animated_button_rect(button, 1);
    else
        update_game_object_frame(button);
    update_appearing_object(button, scene);
    return (true);
}