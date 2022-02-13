/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** rpg_ennemy_update.c
*/

#include "my_game.h"
#include "my.h"
#include "const.h"
#include "fight_scene/ennemy.h"
#include <stdlib.h>

static int rpg_ennemy_update_text(ennemy_t *ennemy, scene_t *scene)
{
    char *tmp1 = my_strcat_nbr("Ennemy's life: ", ennemy->hp);
    char *tmp2 = my_strcat_nbr("Ennemy's shield: ", ennemy->shield);

    if (tmp1 == NULL || tmp2 == NULL)
        return (0);
    sfText_setString(ennemy->hp_text, tmp1);
    sfText_setString(ennemy->shield_text, tmp2);
    free(tmp1);
    free(tmp2);
    return (1);
}

bool rpg_ennemy_update(game_object_t *object, scene_t *scene)
{
    ennemy_t *ennemy = (ennemy_t *) object->extend;

    if (ennemy->in_fight == 1)
        if (rpg_ennemy_update_text(ennemy, scene) == 0)
            return (false);
    return (true);
}