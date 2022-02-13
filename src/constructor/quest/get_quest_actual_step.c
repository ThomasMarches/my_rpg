/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_quest_actual_step
*/

#include "components/quest/quest.h"

step_t *get_quest_actual_step(quest_t *quest)
{
    step_t *actual = NULL;

    for (step_t *tmp = quest->step; tmp; tmp = tmp->next) {
        if (tmp->step_number == quest->actual_step)
            return (tmp);
    }
    return (actual);
}