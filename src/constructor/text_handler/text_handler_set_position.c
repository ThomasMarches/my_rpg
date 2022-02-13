/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** text_handler_set_position
*/

#include "components/text_handler/text_handler.h"

void text_handler_set_position(game_object_t *object, sfVector2f pos)
{
    text_handler_t *text = object->extend;

    sfText_setPosition(text->text, pos);
}