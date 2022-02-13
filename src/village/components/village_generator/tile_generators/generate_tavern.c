/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** generate_tavern
*/

#include "village/village_decor_constructor.h"
#include "my_game.h"

game_object_t *generate_tavern(game_object_t *last, sfVector2f pos, int id,
int z_index)
{
    game_object_t *tile = NULL;

    tile = create_game_object(last, (char *) TILE_PATH[id],
    pos, TILE_MAP);
    if (tile == NULL)
        return (NULL);
    tile->z_index = z_index;
    tile->box = (sfIntRect) {pos.x, pos.y + 2 * 48, 240, 180};
    tile->state = 1;
    tile = create_game_object(tile, (char *) TILE_PATH[0],
    pos, TILE_MAP);
    return (tile);
}