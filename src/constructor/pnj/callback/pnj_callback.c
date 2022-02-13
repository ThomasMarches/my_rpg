/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** callback_pnj.c
*/

#include "components/pnj/pnj.h"
#include "my_game.h"
#include "my.h"
#include <stdlib.h>

static void rpg_dialog_button_set_pnj(game_object_t *object, scene_t *scene, \
pnj_t *pnj)
{
    game_object_t *tmp = scene->objects_list;

    for (; tmp && tmp->type != DIALOG_BUTTON; tmp = tmp->next);
    if (tmp == NULL || tmp->type != DIALOG_BUTTON)
        return;
    tmp->state = (int) pnj->pnj_id;
}

static bool is_dialog_open(game_object_t *object, scene_t *scene)
{
    game_object_t *tmp = scene->objects_list;
    pnj_t *tmp2 = NULL;

    for (; tmp; tmp = tmp->next) {
        if (tmp == NULL)
            return (0);
        else if (tmp->type == PNJ)
            tmp2 = (pnj_t *) tmp->extend;
        if (tmp2 != NULL && tmp2->draw_text == 1)
            return (1);
    }
    return (0);
}

static bool is_player_next_to_npc(game_object_t *object, scene_t *scene, \
pnj_t *pnj)
{
    game_object_t *tmp = scene->objects_list;
    sfIntRect box = {0, 0, 0, 0};

    return (1);
    for (; tmp && tmp->type != PLAYER; tmp = tmp->next);
    if (tmp == NULL || tmp->type != PLAYER)
        return (0);
    box.top = object->pos.y - 100;
    box.width = 200;
    box.left = object->pos.x - 100;
    box.height = 200;
    if (sfIntRect_contains(&box, tmp->pos.x, tmp->pos.y) == 1)
        return (1);
    return (0);
}

bool rpg_pnj_callback(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *) pt;
    pnj_t *pnj = (pnj_t *) object->extend;

    if (is_dialog_open(object, scene) == 1 || \
    is_player_next_to_npc(object, scene, pnj) == 0)
        return (false);
    rpg_dialog_button_set_pnj(object, scene, pnj);
    if (pnj->pnj_type == QUEST_PNJ)
        rpg_pnj_quest_callback(object, scene, pnj);
    else if (pnj->pnj_type == DIALOG_PNJ)
        rpg_pnj_dialog_callback(object, scene, pnj);
    return (false);
}