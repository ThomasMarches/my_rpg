/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** callback_pnj.c
*/

#include "components/pnj/pnj.h"
#include "my_game.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

void rpg_dialog_advance_step(pnj_t *pnj, scene_t *scene, dialog_t *dialog)
{
    for (; dialog && dialog->dialog_step != pnj->dialog_step; \
    dialog = dialog->next);
    if (dialog->dialog_step != pnj->dialog_step)
        return;
    if (dialog->next == NULL) {
        pnj->draw_text = 0;
        pnj->dialog_step = pnj->number_of_step;
        return;
    }
    rpg_dialog_set_text(pnj, scene, dialog);
}