/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** generate_ship
*/

#include "village/village_decor_constructor.h"
#include "my_game.h"

game_object_t *generate_ship(game_object_t *last, sfVector2f pos, int id,
int z_index)
{
    game_object_t *tile = NULL;

    tile = create_game_object(last, (char *) TILE_PATH[id],
    pos, TILE_MAP);
    if (tile == NULL)
        return (NULL);
    tile->z_index = z_index;
    tile->box = (sfIntRect) {pos.x, pos.y, 144, 145};
    tile->state = 2;
    return (tile);
}