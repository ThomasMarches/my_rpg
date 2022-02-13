/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_board_create_from_conf.c
*/

#include "my_game.h"
#include "my_json.h"
#include "components/quest/quest.h"
#include "my.h"
#include "const.h"
#include "item/item_id.h"
#include "item/item_name.h"
#include "components/get_from_config.h"
#include "components/quest/board.h"
#include "font/font.h"
#include "player.h"
#include <stdlib.h>

static quest_board_t *rpg_quest_board_init_actual_step(step_t *tmp, int x, \
quest_board_t *board, char *tmp2)
{
    if (tmp != NULL && tmp->validated == 0) {
        tmp2 = my_strcat("Actual step: ", tmp->description);
        board->actual_step = init_text(tmp2, 75, 450 + (x * 50), \
        (char *) FONT_PATH[1]);
        if (board->actual_step == NULL)
            return (NULL);
        sfText_setCharacterSize(board->actual_step, 30);
        free(tmp2);
    }
    return (board);
}

quest_board_t *rpg_quest_board_init_text(game_t *game, step_t *tmp, \
quest_board_t *board)
{
    char *tmp2 = my_strcat_nbr("Money reward: ", ((player_t *)
    game->player)->quest.reward_money);
    char *tmp3 = my_strcat("Item reward: ", \
    (char *) ITEM_NAME[((player_t *) game->player)->quest.reward_item]);

    if (tmp2 == NULL || tmp3 == NULL)
        return (NULL);
    board->money_reward = init_text(tmp2, 1300, 900, (char *) FONT_PATH[0]);
    board->item_reward = init_text(tmp3, 75, 900, (char *) FONT_PATH[0]);
    if (board->money_reward == NULL || board->item_reward == NULL)
        return (NULL);
    free(tmp2);
    free(tmp3);
    return (board);
}

quest_board_t *rpg_quest_board_init_text_step(step_t *tmp, \
quest_board_t *board)
{
    int x = 0;
    char *tmp2 = NULL;

    board->step_to_draw = 0;
    for (; tmp && tmp->validated == 1 && x < board->number_of_step; \
    tmp = tmp->next, x++) {
        tmp2 = my_strcat(tmp->description, " (COMPLETED)");
        board->steps[x] = init_text(tmp2, 75, 350 + (x * 50), \
        (char *) FONT_PATH[1]);
        if (board->steps[x] == NULL)
            return (NULL);
        sfText_setCharacterSize(board->steps[x], 30);
        free(tmp2);
        board->step_to_draw++;
    }
    board = rpg_quest_board_init_actual_step(tmp, x, board, tmp2);
    return (board);
}