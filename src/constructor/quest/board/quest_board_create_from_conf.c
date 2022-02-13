/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_board_create_from_conf.c
*/

#include "my_game.h"
#include "my_json.h"
#include "components/quest/quest.h"
#include <stdlib.h>
#include "const.h"
#include "components/get_from_config.h"
#include "components/quest/board.h"

void rpg_quest_board_destroy(void *pt)
{
    quest_board_t *board = (quest_board_t *) pt;

    if (board == NULL)
        return;
    free_text(board->title);
    free_text(board->name);
    free_text(board->actual_step);
    free_text(board->item_reward);
    free_text(board->money_reward);
    for (int x = 0; board->steps && x < board->number_of_step; x++)
        free_text(board->steps[x]);
    if (board->steps != NULL)
        free(board->steps);
    free(board);
}

game_object_t *rpg_quest_board_create_from_conf(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = create_game_object(last, \
    get_str_from_conf(js, "texture_path"), (sfVector2f) {0, 0}, QUEST_BOARD);

    if (object == NULL)
        return (NULL);
    object->state = 0;
    object->z_index = scene->z_index_deepth;
    object->draw = &rpg_quest_board_draw;
    object->extend = (void *) rpg_quest_board_create_extend(last, \
    js, game, scene);
    object->free_extend = &rpg_quest_board_destroy;
    object->update = &rpg_quest_board_update_pos;
    if (object->extend == NULL)
        return (NULL);
    return (object);
}