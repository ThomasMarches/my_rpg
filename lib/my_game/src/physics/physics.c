/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** physics
*/

#include "my_game.h"

static const float GRAVITY = 2.0;

void do_solid_collision_objects(game_object_t *actual, game_object_t *object)
{
    if (sfIntRect_intersects(&actual->box, &object->box, NULL)) {
        if (actual->pos.y + actual->box.height <= object->pos.y) {
            actual->move.y = 0;
            actual->pos.y = object->pos.y - actual->box.height;
            actual->box.top = actual->pos.y;
            sfSprite_setPosition(actual->sprite, actual->pos);
        } else if (actual->last_pos.y >= object->pos.y + object->box.height) {
            actual->move.y = GRAVITY;
            actual->pos.y = object->pos.y + object->box.height;
            actual->box.top = actual->pos.y;
            sfSprite_setPosition(actual->sprite, actual->pos);
        }
        if (actual->last_pos.x < object->pos.x) {
            actual->move.x = 0;
            actual->pos.x = object->pos.x - actual->box.width;
            sfSprite_setPosition(actual->sprite, actual->pos);
        }
    }
}

void update_physics(game_object_t *actual, scene_t *scene)
{
    sfIntRect tmp = actual->box;

    actual->move.y += GRAVITY;
    actual->box.top += actual->move.y;
    actual->box.left += actual->move.x;
    actual->box = tmp;
}