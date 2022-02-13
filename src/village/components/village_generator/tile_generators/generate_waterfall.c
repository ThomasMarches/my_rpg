/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** generate_waterfall
*/

#include "my_game.h"
#include "village/village_decor_constructor.h"

game_object_t *generate_waterfall(game_object_t *last, sfVector2f pos, int id,
int z_index)
{
    game_object_t *tile = NULL;

    tile = create_game_object(last, (char *) TILE_PATH[id],
    pos, TILE_MAP);
    if (tile == NULL)
        return (NULL);
    tile->z_index = z_index;
    tile->state = 1;
    tile->box = (sfIntRect) {pos.x, pos.y, 144, 284};
    tile = create_game_object(tile, (char *) TILE_PATH[0],
    pos, TILE_MAP);
    return (tile);
}