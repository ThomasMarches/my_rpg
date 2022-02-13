/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_create
*/

#include "player.h"
#include "components/quest/quest.h"
#include "components/quest/quest_conf.h"
#include <stdlib.h>

player_t *player_create(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return (NULL);
    player->galaxie_dest = (sfVector2f) {0, 0};
    player->item_list = NULL;
    player->quest = rpg_quest_get_from_conf((char *) QUEST_CONF[0], NULL);
    player->quest.state = TAKEN;
    player->planet_conf = NULL;
    return (player);
}