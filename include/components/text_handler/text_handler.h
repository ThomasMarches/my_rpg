/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** constructors
*/

#ifndef TEXT_HANDLER_H_H
#define TEXT_HANDLER_H_H

#include "my_game.h"
#include "my_json.h"

typedef struct text_handler {
    sfText *text;
    sfFont *font;
    int character_size;
    sfColor color;
    sfTextStyle style;
} text_handler_t;

void rpg_text_handler_draw(sfRenderWindow *window, game_object_t *object);
text_handler_t *rpg_text_handler_create_extend_from_conf(game_object_t *object,
json_object_t *js, sfVector2f pos);
void rpg_text_handler_destroy(void *);

#endif /* !TEXT_HANDLER_H_H */
