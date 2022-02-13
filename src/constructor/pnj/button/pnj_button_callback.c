/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pnj_button_callback.c
*/

#include "my_game.h"
#include "components/pnj/pnj.h"
#include "components/quest/quest.h"
#include "player.h"
#include "my.h"
#include <stdlib.h>

static pnj_t *rpg_pnj_get_clicked_pnj(game_object_t *object, scene_t *scene)
{
    game_object_t *tmp_obj = scene->objects_list;
    pnj_t *pnj = NULL;

    for (; tmp_obj; tmp_obj = tmp_obj->next) {
        if (tmp_obj->type == PNJ)
            pnj = (pnj_t *) tmp_obj->extend;
        if (pnj && (int) pnj->pnj_id == object->state)
            return (pnj);
    }
    return (NULL);
}

void rpg_pnj_button_callback_quest_npc(pnj_t *pnj, scene_t *scene,
dialog_t *tmp)
{
    if (pnj->quest_statue == GET_QUEST) {
        rpg_quest_dialog_advance_step(pnj, scene, tmp);
    } else if (pnj->quest_statue == GIVE_BACK_QUEST) {
        validate_quest(scene->game, scene, &((player_t *)
        scene->game->player)->quest);
        pnj->draw_text = 0;
    } else
        pnj->draw_text = 0;
}

bool rpg_pnj_button_callback(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *) pt;
    pnj_t *pnj = rpg_pnj_get_clicked_pnj(object, scene);
    dialog_t *tmp = NULL;

    if (pnj == NULL)
        return (false);
    tmp = pnj->dialog;
    if (pnj->pnj_type == QUEST_PNJ)
        rpg_pnj_button_callback_quest_npc(pnj, scene, tmp);
    else if (pnj->pnj_type == DIALOG_PNJ)
        rpg_dialog_advance_step(pnj, scene, tmp);
    return (false);
}