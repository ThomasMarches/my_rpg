/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight_handler_callback.c
*/

#include "fight_scene/fight_handler.h"

static bool rpg_fight_handler_empty_check(fight_handler_t *handler)
{
    if (handler->id[handler->done] == EMPTY)
        return (false);
    handler->done++;
    return (false);
}

bool rpg_fight_handler_callback(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *) pt;
    sfVector2f pos = get_mouse_exact_pos(scene->window);
    fight_handler_t *handler = (fight_handler_t *) object->extend;

    if (handler->done == handler->action_number || handler->in_fight == 0)
        return (false);
    for (game_object_t *tmp = handler->button; tmp; tmp = tmp->next) {
        handler->id[handler->done] = (sfIntRect_contains(&tmp->box, pos.x,
        pos.y) && tmp->type == ATTACK_BUTTON) ? ATTACK :
        handler->id[handler->done];
        handler->id[handler->done] = (sfIntRect_contains(&tmp->box, pos.x,
        pos.y) && tmp->type == REPAIR_BUTTON &&
        rpg_fight_handler_spaceship_get_repair_statue(scene) >= 3) ?
        REPAIR : handler->id[handler->done];
        handler->id[handler->done] = (sfIntRect_contains(&tmp->box, pos.x, pos.y
        ) && tmp->type == DODGE_BUTTON) ? DODGE : handler->id[handler->done];
    }
    return (rpg_fight_handler_empty_check(handler));
}