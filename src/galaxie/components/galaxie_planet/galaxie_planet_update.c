/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_planet_update
*/

#include "galaxie/galaxie_planet.h"

bool galaxie_planet_update(game_object_t *object, scene_t * scene)
{
    update_game_object_frame(object);
    return (true);
}