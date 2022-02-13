/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** move_event
*/

#include "my_game.h"
#include "village/village_player.h"

static sfVector2f get_move_from_key(int key)
{
    sfVector2f new_move = {0, 0};

    switch (key) {
    case sfKeyDown:
        new_move.y = SPEED;
        break;
    case sfKeyUp:
        new_move.y = -SPEED;
        break;
    case sfKeyRight:
        new_move.x = SPEED;
        break;
    case sfKeyLeft:
        new_move.x = -SPEED;
        break;
    default:
        break;
    }
    return new_move;
}

void village_move_event(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window)
{
    sfVector2f new_move = {0, 0};
    game_object_t *tmp = scene->objects_list;

    for (; tmp && tmp->type != PLAYER; tmp = tmp->next);
    if (!tmp || tmp->type != PLAYER)
        return;
    new_move = get_move_from_key(event.key.code);
    tmp->move = new_move;
}