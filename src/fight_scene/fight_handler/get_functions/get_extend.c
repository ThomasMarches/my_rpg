/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fighthandler.c
*/

#include "fight_scene/fight_handler.h"
#include "fight_scene/ship.h"
#include "fight_scene/ennemy.h"

ennemy_t *rpg_ennemy_get_extend(scene_t *scene)
{
    game_object_t *tmp = NULL;
    ennemy_t *ennemy = NULL;

    for (tmp = scene->objects_list; tmp && tmp->type != ENNEMY; \
    tmp = tmp->next);
    if (tmp == NULL || tmp->type != ENNEMY)
        return (NULL);
    ennemy = (ennemy_t *) tmp->extend;
    if (ennemy == NULL)
        return (NULL);
    return (ennemy);
}

space_ship_t *rpg_spaceship_get_extend(scene_t *scene)
{
    game_object_t *tmp = NULL;
    space_ship_t *ship = NULL;

    for (tmp = scene->objects_list; tmp && tmp->type != SPACESHIP; \
    tmp = tmp->next);
    if (tmp == NULL || tmp->type != SPACESHIP)
        return (NULL);
    ship = (space_ship_t *) tmp->extend;
    if (ship == NULL)
        return (NULL);
    return (ship);
}

fight_handler_t *rpg_fight_handler_get_extend(scene_t *scene)
{
    game_object_t *tmp = NULL;
    fight_handler_t *handler = NULL;

    for (tmp = scene->objects_list; tmp && tmp->type != FIGHT_HANDLER; \
    tmp = tmp->next);
    if (tmp == NULL || tmp->type != FIGHT_HANDLER)
        return (NULL);
    handler = (fight_handler_t *) tmp->extend;
    if (handler == NULL)
        return (NULL);
    return (handler);
}