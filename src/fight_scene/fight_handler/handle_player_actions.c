/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fighthandler.c
*/

#include "my_game.h"
#include "fight_scene/fight_handler.h"

int rpg_fight_handler_make_player_actions(game_object_t *object, \
scene_t *scene)
{
    fight_handler_t *handler = (fight_handler_t *) object->extend;
    int dodge = 0;

    if (handler->done != handler->action_number)
        return (0);
    for (int x = 0; x != handler->action_number; x++) {
        if (handler->id[x] == ATTACK)
            rpg_fight_handler_remove_ennemy_life(object, scene);
        if (handler->id[x] == REPAIR)
            rpg_fight_handler_repair_spaceship(object, scene);
        if (handler->id[x] == DODGE)
            dodge++;
    }
    rpg_fight_handler_handle_dodge_spaceship(object, dodge, scene);
    handler->done = 0;
    for (int x = 0; x != handler->action_number; x++)
        handler->id[x] = EMPTY;
    return (0);
}