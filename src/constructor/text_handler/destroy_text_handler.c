/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_text_handler
*/

#include "components/text_handler/text_handler.h"
#include <stdlib.h>

void rpg_text_handler_destroy(void *pt)
{
    text_handler_t *text = NULL;

    if (pt == NULL)
        return;
    text = (text_handler_t *) pt;
    if (text->font != NULL)
        sfFont_destroy(text->font);
    if (text->text != NULL)
        sfText_destroy(text->text);
    free(text);
}