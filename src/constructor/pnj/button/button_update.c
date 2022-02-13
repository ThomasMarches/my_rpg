/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pnj_update.c
*/

#include "my_game.h"
#include "components/pnj/pnj.h"

bool rpg_pnj_button_update(game_object_t *object, scene_t *scene)
{
    game_object_t *tmp_obj = scene->objects_list;
    pnj_t *pnj = NULL;

    for (; tmp_obj; tmp_obj = tmp_obj->next) {
        if (tmp_obj->type == PNJ)
            pnj = (pnj_t *) tmp_obj->extend;
        if (pnj && pnj->draw_text == 1) {
            object->draw = &draw_object;
            return (true);
        }
    }
    object->draw = NULL;
    return (true);
}