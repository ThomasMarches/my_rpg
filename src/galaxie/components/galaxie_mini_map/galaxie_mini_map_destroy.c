/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_mini_map_destroy
*/

#include "galaxie/galaxie_minimap.h"
#include <stdlib.h>

void galaxie_mini_map_destroy(void *pt)
{
    galaxie_mini_map_t *map = pt;

    if (map == NULL)
        return;
    if (map->view)
        sfView_destroy(map->view);
    if (map->background_path)
        free(map->background_path);
    free(map);
}