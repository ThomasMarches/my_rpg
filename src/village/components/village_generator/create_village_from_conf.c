/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_village_from_conf
*/

#include "my_json.h"
#include "my_game.h"
#include "components/get_from_config.h"
#include "village/village_decor_constructor.h"
#include "village/village_tile_constructors.h"

game_object_t *generate_tile(game_object_t *last, sfVector2f pos, int id,
int z_index)
{
    game_object_t *tile = NULL;

    tile = create_game_object(last, (char *) TILE_PATH[id],
    pos, TILE_MAP);
    if (id != GRASS || id != PATH)
        tile->state = 1;
    return (tile);
}

game_object_t *generate_map_line(game_object_t *last, json_array_t *arr,
sfVector2f size, scene_t *scene)
{
    game_object_t *tmp = NULL;
    static int z_index = 0;
    json_value_t *value = NULL;

    z_index += 1;
    scene->z_index_deepth = z_index;
    for (int i = 0; i < arr->elem_count; i++) {
        value = arr->array[i];
        if (value->value_type == INT && *((int *) value->value) < MAX_TILE_ID
        && *((int *) value->value) >= 0) {
            tmp = TILE_GENERATORS[*((int *) value->value)](last, (sfVector2f)
            {size.x * i, size.y}, *((int *) value->value), z_index);
            last = (tmp) ? tmp : last;
        }
    }
    return (last);
}

game_object_t *create_village(game_object_t *last, json_object_t *js,
game_t *game, scene_t *scene)
{
    json_value_t *value = NULL;
    json_array_t *arr = NULL;
    game_object_t *tmp = NULL;
    int tile_height = 0;
    int tile_width = 0;

    if (!get_int_from_conf(js, &tile_height, "tile_height") ||
    !get_int_from_conf(js, &tile_width, "tile_width"))
        return (last);
    value = json_get_element_by_key(js, "map");
    if (!value || value->value_type != ARRAY)
        return (last);
    arr = value->value;
    for (int i = 0; i < arr->elem_count; i++)
        if (arr->array[i]->value_type == ARRAY) {
            tmp = generate_map_line(last, arr->array[i]->value,
            (sfVector2f) {tile_width, tile_height * i}, scene);
            last = (tmp) ? tmp : last;
        }
    return (last);
}