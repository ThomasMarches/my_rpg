/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_save
*/

#include "player.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static void player_save_inventory(player_t *player, FILE *fd)
{
    for (inventory_t *tmp = player->item_list; tmp; tmp = tmp->next) {
        fwrite(&tmp->id, sizeof(int), 1, fd);
        fwrite(&tmp->item_number, sizeof(int), 1, fd);
    }
}

void player_save(void *pt)
{
    player_t *player = pt;
    FILE *fd = fopen("save/save", "wb");

    if (fd == NULL)
        return;
    fwrite(player, sizeof(player_t), 1, fd);
    player_save_inventory(player, fd);
    fclose(fd);
}