/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** callback_sound_bar
*/

#include "my_game.h"

bool rpg_options_sound_bar_callback(game_object_t *object, void *pt)
{
    object->state = SELECTED;
    return (false);
}