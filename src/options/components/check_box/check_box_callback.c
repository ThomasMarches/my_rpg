/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** check_box_callback
*/

#include "options_menu/check_box.h"

bool rpg_check_box_callback(game_object_t *object, void *pt)
{
    object->state = !object->state;
    return (false);
}