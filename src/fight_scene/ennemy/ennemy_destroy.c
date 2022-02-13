/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_ennemy.c
*/

#include "fight_scene/ennemy.h"
#include "fight_scene/fight_handler.h"
#include <stdlib.h>

void rpg_ennemy_destroy(void *ptr)
{
    ennemy_t *ennemy = NULL;

    if (ptr == NULL)
        return;
    ennemy = (ennemy_t *) ptr;
    if (ennemy->id != NULL)
        free(ennemy->id);
    free_text(ennemy->name_text);
    free_text(ennemy->hp_text);
    free_text(ennemy->shield_text);
    free(ennemy);
}