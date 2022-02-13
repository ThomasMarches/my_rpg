/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pnj_constructors
*/

#include "components/pnj/pnj.h"
#include "player.h"

game_object_t *rpg_pnj_constructor(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *tmp = NULL;
    player_t *player = game->player;
    json_object_t *js2 = NULL;
    json_value_t *value = NULL;
    json_array_t *array = NULL;

    if (player->planet_conf == NULL)
        return (NULL);
    js2 = json_create_from_file(player->planet_conf);
    if (js2 == NULL)
        return (NULL);
    value = json_get_element_by_key(js2, "pnjs");
    array = (value == NULL || value->value_type != ARRAY) ? NULL : value->value;
    for (int i = 0; array && i < array->elem_count; i++) {
        if (array->array[i]->value_type == OBJECT)
        tmp = rpg_pnj_init_from_conf(last, array->array[i]->value, game, scene);
        last = (tmp) ? tmp : last;
    }
    json_object_destroy(js2);
    return (last);
}