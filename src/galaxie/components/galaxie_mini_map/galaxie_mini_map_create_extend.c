/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_mini_map_create_extend
*/

#include "galaxie/galaxie_minimap.h"
#include "components/get_from_config.h"
#include <stdlib.h>

galaxie_mini_map_t *galaxie_minimap_create_extend(json_object_t *js,
game_t *game, scene_t *scene)
{
    galaxie_mini_map_t *map = malloc(sizeof(galaxie_mini_map_t));
    char *background_path = my_strdup(get_str_from_conf(js,
    "background_texture"));
    sfView *view = sfView_create();

    if (map == NULL || background_path == NULL || view == NULL)
        return (NULL);
    sfView_setViewport(view, (sfFloatRect) {0.75f, 0.f, 0.25f, 0.25f});
    sfView_setSize(view, (sfVector2f) {game->window->width * 2,
    game->window->height * 2});
    map->view = view;
    map->scene = scene;
    map->background_path = background_path;
    return (map);
}