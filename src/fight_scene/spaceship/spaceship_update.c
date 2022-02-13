/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** spaceship_update.c
*/

#include "my_game.h"
#include "my.h"
#include "fight_scene/ship.h"
#include "fight_scene/fight_handler.h"
#include <stdlib.h>

static int rpg_spaceship_update_text(space_ship_t *space_ship, scene_t *scene)
{
    char *tmp1 = my_strcat_nbr("Your life: ", space_ship->hp);
    char *tmp2 = my_strcat_nbr("Your shield: ", space_ship->shield);
    char *tmp3 = my_strcat_nbr("Actions left: ", rpg_get_left_actions(scene));

    if (tmp1 == NULL || tmp2 == NULL || tmp3 == NULL) {
        rpg_space_ship_destroy_tmp_text(tmp1, tmp2, tmp3);
        return (0);
    }
    sfText_setString(space_ship->hp_text, tmp1);
    sfText_setString(space_ship->shield_text, tmp2);
    sfText_setString(space_ship->action_left, tmp3);
    rpg_space_ship_destroy_tmp_text(tmp1, tmp2, tmp3);
    if (space_ship->repair_statue >= 3 && space_ship->hp < space_ship->max_hp)
        sfText_setString(space_ship->repair_turn_left, "Repair statue: Able");
    return (1);
}

bool rpg_spaceship_update(game_object_t *object, scene_t *scene)
{
    space_ship_t *space_ship = (space_ship_t *) object->extend;

    if (space_ship->in_fight == 1)
        if (rpg_spaceship_update_text(space_ship, scene) == 0)
            return (false);
    return (true);
}