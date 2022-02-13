/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** open_quest_board.c
*/

#include "my_game.h"

void open_quest_board(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window)
{
    game_object_t *tmp = scene->objects_list;
    sfKeyCode key = event.key.code;

    if (key != sfKeyL)
        return;
    for (; tmp && tmp->type != QUEST_BOARD; tmp = tmp->next);
    if (tmp == NULL)
        return;
    if (tmp->type == QUEST_BOARD && tmp->state == 0)
        tmp->state = 1;
    else if (tmp->type == QUEST_BOARD)
        tmp->state = 0;
}