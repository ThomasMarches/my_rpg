/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_quest->c
*/

#include "my_json.h"
#include <stdlib.h>
#include "components/get_from_config.h"
#include "components/quest/quest.h"

quest_t rpg_init_quest(game_t *game)
{
    quest_t quest;

    quest.state = UNTAKEN;
    quest.actual_step = 1;
    quest.step = NULL;
    quest.name = NULL;
    quest.number_of_step = 0;
    quest.reward_money = 0;
    quest.reward_item = -1;
    quest.id = 0;
    return (quest);
}