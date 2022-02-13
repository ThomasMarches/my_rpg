/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fighthandler.c
*/

#include "my_game.h"
#include "fight_scene/fight_handler.h"
#include "fight_scene/ennemy.h"
#include <stdlib.h>

int rpg_ennemy_get_dodge_value(game_object_t *object, scene_t *scene)
{
    ennemy_t *ennemy = rpg_ennemy_get_extend(scene);
    int dodge_value = 0;

    if (ennemy == NULL)
        return (0);
    dodge_value = ennemy->dodge_value;
    return (dodge_value);
}