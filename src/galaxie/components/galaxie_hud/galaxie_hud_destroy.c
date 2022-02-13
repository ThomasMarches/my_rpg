/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_hud_destroy
*/

#include "galaxie/galaxie_hud.h"
#include <stdlib.h>

void galaxie_hud_destroy(void *pt)
{
    galaxie_hud_t *hud = pt;

    destroy_game_object(hud->scene, hud->button);
    destroy_game_object(hud->scene, hud->planet_name);
    destroy_game_object(hud->scene, hud->player_pos);
    free(hud);
}