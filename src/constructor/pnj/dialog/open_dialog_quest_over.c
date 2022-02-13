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

void rpg_pnj_open_dialog_quest_over(pnj_t *pnj, scene_t *scene)
{
    dialog_t *tmp = pnj->dialog;
    char *str_tmp = pnj->name;

    if (tmp == NULL)
        return;
    pnj->draw_text = 1;
    for (; tmp && tmp->dialog_statue != GIVE_BACK_QUEST; tmp = tmp->next);
    if (tmp->dialog_statue != GIVE_BACK_QUEST)
        return;
    pnj->dialog_text = init_text(str_tmp = my_strcat(str_tmp, tmp->text), \
    75, 950, (char *) FONT_PATH[1]);
    if (str_tmp != NULL)
        free(str_tmp);
    pnj->quest_statue = GIVE_BACK_QUEST;
}