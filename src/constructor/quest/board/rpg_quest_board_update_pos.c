/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg_quest_board_update_pos
*/

#include "components/quest/quest.h"

bool rpg_quest_board_update_pos(game_object_t *object,
scene_t *scene)
{
    quest_board_t *board = object->extend;
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(scene->window));
    int i = 0;

    pos = (sfVector2f) {pos.x - 1920 / 2, pos.y - 1080 / 2};
    sfSprite_setPosition(object->sprite, (sfVector2f) {pos.x, pos.y});
    sfText_setPosition(board->name, (sfVector2f) {pos.x + 400, pos.y + 250});
    for (; i < board->number_of_step && board->steps[i] != NULL; i++) {
        sfText_setPosition(board->steps[i], (sfVector2f) {pos.x + 75,
        pos.y + 350 + (i * 50)});
    }
    sfText_setPosition(board->actual_step, (sfVector2f) {75 + pos.x,
    pos.y + 450 + (i * 50)});
    sfText_setPosition(board->money_reward, (sfVector2f) {1300 + pos.x,
    900 + pos.y});
    sfText_setPosition(board->item_reward, (sfVector2f) {75 + pos.x,
    900 + pos.y});
    sfText_setPosition(board->title, (sfVector2f) {500 + pos.x, 50 + pos.y});
    return (true);
}