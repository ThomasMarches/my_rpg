/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** generate_grass
*/

#include "my_game.h"
#include "village/village_decor_constructor.h"

game_object_t *generate_grass(game_object_t *last, sfVector2f pos, int id,
int z_index)
{
    game_object_t *tile = NULL;

    tile = create_game_object(last, (char *) TILE_PATH[id],
    pos, TILE_MAP);
    return (tile);
}