/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main_menu
*/

#include "my_rpg.h"
#include <stdlib.h>

bool rpg_update_parallax(game_object_t *object, scene_t *scene)
{
    sfSprite_move(object->sprite, (sfVector2f) {-2, 0});
    object->pos = sfSprite_getPosition(object->sprite);
    if (object->pos.x <= -1920)
        sfSprite_setPosition(object->sprite, (sfVector2f) {0, 0});
    return (update_appearing_object(object, scene));
}