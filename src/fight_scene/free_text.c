/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** free_text.c
*/

#include "my_game.h"

void free_text(sfText *text)
{
    if (text != NULL) {
        sfFont_destroy((sfFont *) sfText_getFont(text));
        sfText_destroy(text);
    }
}