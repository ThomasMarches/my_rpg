/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_player_from_conf
*/

#include "my_json.h"
#include "my_game.h"
#include "components/get_from_config.h"
#include "village/village_player.h"
#include "player.h"

static int get_state_by_move(game_object_t *object)
{
    if (object->move.y != 0) {
        if (object->move.y < 0)
            return PLAYER_UP;
        else
            return PLAYER_DOWN;
    }
    if (object->move.x != 0) {
        if (object->move.x < 0)
            return PLAYER_LEFT;
        else
            return PLAYER_RIGHT;
    }
    return -1;
}

static void update_state(game_object_t *object)
{
    int next_state = get_state_by_move(object);

    if (next_state == -1)
        return;
    if (object->state != next_state)
        update_game_object_state(object, next_state);
    else {
        move_object(object);
        update_game_object_frame(object);
    }
}

static bool check_player_move(game_object_t *object, scene_t *scene)
{
    sfIntRect next_pos = {object->pos.x + object->move.x,
    object->pos.y + object->move.y + object->box.height / 2,
    object->box.width, object->box.height / 2};

    for (game_object_t *tmp = scene->objects_list; tmp; tmp = tmp->next) {
        if (tmp->type == PLAYER)
            continue;
        if (tmp->state == 2 && sfIntRect_intersects(&next_pos, &tmp->box,
        NULL)) {
            scene->display = GALAXIE_SCENE;
            return (false);
        }
        if (tmp->state == 1 && sfIntRect_intersects(&next_pos, &tmp->box, NULL))
            return (false);
    }
    return (true);
}

bool update_player(game_object_t *object, scene_t *scene)
{
    sfVector2f reset = {0, 0};

    if (object->move.y != 0 || object->move.x != 0) {
        if (check_player_move(object, scene)) {
            update_state(object);
            object->move = reset;
            object->z_index = object->pos.y / 48;
        }
    }
    player_check_end(object, scene);
    return (true);
}