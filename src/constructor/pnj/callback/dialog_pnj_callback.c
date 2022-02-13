/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** callback_pnj.c
*/

#include "components/pnj/pnj.h"
#include "my_game.h"
#include "my.h"
#include "font/font.h"
#include <stdlib.h>

void rpg_pnj_dialog_callback(game_object_t *object, scene_t *scene, pnj_t *pnj)
{
    dialog_t *tmp = pnj->dialog;
    char *str_tmp = pnj->name;

    if (tmp == NULL)
        return;
    pnj->draw_text = 1;
    pnj->dialog_text = init_text(str_tmp = my_strcat(str_tmp, tmp->text), \
    75, 950, (char *) FONT_PATH[1]);
    if (str_tmp != NULL)
        free(str_tmp);
    pnj->dialog_step = pnj->number_of_step;
}