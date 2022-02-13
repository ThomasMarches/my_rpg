/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy_quest.c
*/

#include "components/quest/quest.h"
#include <stdlib.h>

static void free_step(step_t *step)
{
    if (step == NULL)
        return;
    if (step->description)
        free(step->description);
    if (step->fight_scene)
        free(step->fight_scene);
    free(step);
}

void rpg_destroy_quest(quest_t *quest)
{
    step_t *tmp = NULL;
    step_t *step = NULL;

    if (quest == NULL)
        return;
    if (quest->name != NULL)
        free(quest->name);
    if (quest->step != NULL) {
        step = quest->step;
        for (; step; step = tmp) {
            tmp = step->next;
            free_step(step);
        }
    }
}