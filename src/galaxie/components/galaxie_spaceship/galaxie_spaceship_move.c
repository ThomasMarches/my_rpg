/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_spaceship_move
*/

#include "galaxie/galaxie_spaceship.h"
#include "player.h"
#include "my_abs.h"

static void galaxie_spaceship_scale_move_vector(game_object_t *object)
{
    float tmp = 0;

    if (ABS(object->move.x) <= 10 && ABS(object->move.y) <= 10)
        return;
    if (ABS(object->move.x) > ABS(object->move.y)) {
        tmp = object->move.x;
        object->move.x = (object->move.x > 0) ? 10 : - 10;
        object->move.y = (object->move.x < 0) ?
        - 10 * object->move.y / tmp : 10 * object->move.y / tmp;
    } else if (ABS(object->move.y) > ABS(object->move.x)) {
        tmp = object->move.y;
        object->move.y = (object->move.y > 0) ? 10 : -10;
        object->move.x = (object->move.y < 0) ?
        - 10 * object->move.x / tmp : 10 * object->move.x / tmp;
    } else {
        object->move.y = (object->move.y > 0) ? 10 : -10;
        object->move.x = (object->move.x > 0) ? 10 : - 10;
    }
}

static void galaxie_spaceship_compute_move_vector(game_object_t *object)
{
    player_t *player = object->extend;
    sfVector2f center = object->pos;

    object->move.x = player->galaxie_dest.x - center.x;
    object->move.y = player->galaxie_dest.y - center.y;
    galaxie_spaceship_scale_move_vector(object);
}

void galaxie_spaceship_move(game_object_t *object, scene_t *scene)
{
    sfView *view = (sfView *) sfRenderWindow_getView(scene->window);
    sfVector2f pos = {0, 0};

    if (view == NULL)
        return;
    galaxie_spaceship_compute_move_vector(object);
    move_object(object);
    pos.x = object->pos.x;
    pos.y = object->pos.y;
    sfView_setCenter(view, pos);
    sfRenderWindow_setView(scene->window, view);
}