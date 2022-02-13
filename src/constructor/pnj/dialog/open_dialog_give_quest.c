/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** callback_pnj.c
*/

#include "components/pnj/pnj.h"
#include "components/quest/quest_conf.h"
#include "my_game.h"
#include "my.h"
#include "font/font.h"
#include "player.h"
#include <stdlib.h>

void rpg_pnj_open_dialog_give_quest(pnj_t *pnj, scene_t *scene)
{
    dialog_t *tmp = pnj->dialog;
    char *str_tmp = pnj->name;

    if (tmp == NULL || pnj->quest_id != 0)
        return;
    ((player_t *) scene->game->player)->quest = rpg_quest_get_from_conf(
    (char *) QUEST_CONF[pnj->quest_id], scene);
    pnj->draw_text = 1;
    for (; tmp && tmp->dialog_statue != GET_QUEST; tmp = tmp->next);
    if (tmp->dialog_statue != GET_QUEST)
        return;
    pnj->dialog_text = init_text(str_tmp = my_strcat(str_tmp, tmp->text), \
    75, 950, (char *) FONT_PATH[1]);
    if (str_tmp != NULL)
        free(str_tmp);
    pnj->dialog_step = 3;
    pnj->quest_statue = GET_QUEST;
}