/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_ennemy.c
*/

#include "my_game.h"
#include "fight_scene/fight_handler.h"
#include "fight_scene/ship.h"

item_id rpg_spaceship_get_equiped_weapon(game_object_t *object, scene_t *scene)
{
    space_ship_t *ship = rpg_spaceship_get_extend(scene);
    item_id weapon = 0;

    if (ship == NULL)
        return (0);
    weapon = ship->equiped_weapon;
    return (weapon);
}

int rpg_spaceship_get_equip_size(game_object_t *object, scene_t *scene)
{
    space_ship_t *ship = rpg_spaceship_get_extend(scene);
    int member_in_ship = 0;

    if (ship == NULL)
        return (0);
    member_in_ship = ship->member_in_ship;
    return (member_in_ship);
}

int rpg_spaceship_get_damage(game_object_t *object, scene_t *scene)
{
    space_ship_t *ship = rpg_spaceship_get_extend(scene);
    int damage = 0;

    if (ship == NULL)
        return (0);
    damage = ship->damage;
    return (damage);
}

int rpg_spaceship_get_repair_value(game_object_t *object, scene_t *scene)
{
    space_ship_t *ship = rpg_spaceship_get_extend(scene);
    int repair_value = 0;

    if (ship == NULL)
        return (0);
    repair_value = ship->repair_value;
    return (repair_value);
}

int rpg_spaceship_get_dodge_value(game_object_t *object, scene_t *scene)
{
    space_ship_t *ship = rpg_spaceship_get_extend(scene);
    int dodge_value = 0;

    if (ship == NULL)
        return (0);
    dodge_value = ship->dodge_value;
    return (dodge_value);
}