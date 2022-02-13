/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** callback_pnj.c
*/

#include "components/pnj/pnj.h"
#include "my_game.h"
#include "my.h"
#include "player.h"
#include <stdlib.h>

void rpg_pnj_quest_callback(game_object_t *object, scene_t *scene, pnj_t *pnj)
{
    player_t *player = scene->game->player;

    if (player->quest.state == UNTAKEN ||
    player->quest.state == RESET) {
        rpg_pnj_open_dialog_give_quest(pnj, scene);
        return;
    } else if (player->quest.state == TAKEN && \
    player->quest.id == pnj->quest_id) {
        rpg_pnj_open_dialog_doing_quest(pnj, scene);
        return;
    }
    if (player->quest.state == ACHIEVED  && \
    player->quest.id == pnj->quest_id)
        rpg_pnj_open_dialog_quest_over(pnj, scene);
}