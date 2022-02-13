/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** generate_rock
*/

#include "my_game.h"
#include "village/village_decor_constructor.h"

game_object_t *generate_rocks(game_object_t *last, sfVector2f pos, int id,
int z_index)
{
    game_object_t *tile = NULL;

    tile = create_game_object(last, (char *) TILE_PATH[id],
    pos, TILE_MAP);
    tile->z_index = z_index - 1;
    tile->box = (sfIntRect) {pos.x, pos.y, 48, 123};
    tile->state = 1;
    return (tile);
}