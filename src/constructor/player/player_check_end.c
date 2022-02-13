/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_check_end
*/

#include "player.h"
#include "components/quest/quest.h"

void player_check_end(game_object_t *object, scene_t *scene)
{
    player_t *player = object->extend;

    if (player->quest.id == MAX_QUEST_ID - 1)
        scene->display = END_SCENE;
}