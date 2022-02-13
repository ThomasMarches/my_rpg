/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_qest_from_save
*/

#include "components/quest/quest_conf.h"
#include "components/quest/quest.h"
#include "components/quest/board.h"

void rpg_quest_load_from_save(quest_t *quest)
{
    quest_t quest2 = rpg_quest_get_from_conf((char *) QUEST_CONF[quest->id],
    NULL);
    step_t *tmp = NULL;

    quest->step = quest2.step;
    quest->name = quest2.name;
    tmp = quest->step;
    for (; tmp && tmp->step_number < quest->actual_step; tmp = tmp->next)
        tmp->validated = true;
}