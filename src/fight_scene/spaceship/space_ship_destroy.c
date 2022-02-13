/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_space_ship.c
*/

#include "fight_scene/ship.h"
#include "fight_scene/fight_handler.h"
#include <stdlib.h>

void rpg_space_ship_destroy(void *ptr)
{
    space_ship_t *space_ship = NULL;

    if (ptr == NULL)
        return;
    space_ship = (space_ship_t *) ptr;
    free_text(space_ship->hp_text);
    free_text(space_ship->shield_text);
    free_text(space_ship->repair_turn_left);
    free_text(space_ship->action_left);
    free(space_ship);
}