/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_background_update
*/

#include "galaxie/galaxie_background.h"
#include "my_abs.h"

bool galaxie_background_update(game_object_t *object, scene_t *scene)
{
    sfVector2f range = {0, 0};
    galaxie_mini_map_t *map = object->extend;
    sfVector2f center = sfView_getCenter(map->view);

    range.x = object->pos.x - center.x;
    range.y = object->pos.y - center.y;
    if (ABS(range.x) > 1920 * 4)
        object->pos.x += 1920;
    else if (ABS(range.x) < 1920 * 3)
        object->pos.x -= 1920;
    else {
        if (ABS(range.y) > 1080 * 4)
            object->pos.y += 1080;
        else if (ABS(range.y) < 1080 * 3)
            object->pos.y -= 1080;
    }
    sfSprite_setPosition(object->sprite, object->pos);
    return (true);
}