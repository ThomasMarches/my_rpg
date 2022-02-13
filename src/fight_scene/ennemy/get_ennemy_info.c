/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_ennemy.c
*/

#include "fight_scene/ennemy.h"
#include "fight_scene/fight_handler.h"

item_id rpg_ennemy_get_equiped_weapon(game_object_t *object, scene_t *scene)
{
    ennemy_t *ennemy = rpg_ennemy_get_extend(scene);
    item_id weapon = 0;

    if (ennemy == NULL)
        return (0);
    weapon = ennemy->equiped_weapon;
    return (weapon);
}

int rpg_ennemy_get_damage(game_object_t *object, scene_t *scene)
{
    ennemy_t *ennemy = rpg_ennemy_get_extend(scene);
    int damage = 0;

    if (ennemy == NULL)
        return (0);
    damage = ennemy->damage;
    return (damage);
}