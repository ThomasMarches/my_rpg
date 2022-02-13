/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_bord_update.c
*/

#include "my_game.h"
#include "components/quest/board.h"
#include "components/quest/quest.h"
#include "player.h"

void rpg_quest_board_update(scene_t *scene)
{
    game_object_t *tmp = NULL;

    if (scene && scene->objects_list != NULL)
        tmp = scene->objects_list;
    for (; tmp && tmp->type != QUEST_BOARD; tmp = tmp->next);
    if (!tmp)
        return;
    tmp->extend = (void *) rpg_quest_board_setup((quest_board_t *) \
    tmp->extend, scene->game);
}

quest_board_t *rpg_quest_board_update_text(quest_board_t *board, \
scene_t *scene)
{
    if (board == NULL)
        return (NULL);
    board = rpg_quest_board_init_text_step(((player_t *)
    scene->game->player)->quest.step, board);
    return (board);
}
