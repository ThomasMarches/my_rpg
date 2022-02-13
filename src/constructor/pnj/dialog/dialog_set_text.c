/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pnj_update.c
*/

#include "my_game.h"
#include "components/pnj/pnj.h"
#include "components/quest/quest.h"
#include "font/font.h"
#include <stdlib.h>
#include "my.h"

void rpg_dialog_set_text(pnj_t *pnj, scene_t *scene, dialog_t *dialog)
{
    char *str_tmp = pnj->name;

    pnj->dialog_step--;
    if (pnj->dialog_text != NULL)
        free_text(pnj->dialog_text);
    if (dialog->next->speaker == 1) {
        pnj->dialog_text = init_text(str_tmp = my_strcat(str_tmp, \
        dialog->next->text), 75, 950, (char *) FONT_PATH[1]);
    } else {
        pnj->dialog_text = init_text(str_tmp = my_strcat("You", \
        dialog->next->text), 75, 950, (char *) FONT_PATH[1]);
    }
    if (str_tmp != NULL)
        free(str_tmp);
}