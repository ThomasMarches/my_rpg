/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_board_draw.c
*/

#include "my_game.h"
#include "components/quest/board.h"
#include "stdio.h"

void rpg_quest_board_draw(sfRenderWindow *window, game_object_t *object)
{
    quest_board_t *board = (quest_board_t *) object->extend;

    if (object->state == 0)
        return;
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
    sfRenderWindow_drawText(window, board->title, NULL);
    if (board->draw_infos == 0)
        return;
    sfRenderWindow_drawText(window, board->name, NULL);
    sfRenderWindow_drawText(window, board->money_reward, NULL);
    sfRenderWindow_drawText(window, board->item_reward, NULL);
    if (board->actual_step != NULL)
        sfRenderWindow_drawText(window, board->actual_step, NULL);
    for (int x = 0; x < board->step_to_draw; x++)
        sfRenderWindow_drawText(window, board->steps[x], NULL);
}