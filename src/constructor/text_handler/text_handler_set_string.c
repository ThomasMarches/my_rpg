/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** text_handler_set_string
*/

#include "components/text_handler/text_handler.h"

void text_handler_set_string(game_object_t *object, char *str)
{
    text_handler_t *text = object->extend;

    if (str == NULL)
        return;
    sfText_setString(text->text, str);
}