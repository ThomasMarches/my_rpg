/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_text_from_conf.c
*/

#include "my_json.h"
#include "my_game.h"
#include "components/text_handler/text_handler.h"
#include "components/get_from_config.h"
#include "components/decor/decor_constructor.h"

void rpg_text_handler_draw(sfRenderWindow *window, game_object_t *object)
{
    text_handler_t *text = (text_handler_t *) object->extend;

    sfRenderWindow_drawText(window, text->text, NULL);
}