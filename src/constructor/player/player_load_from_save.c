/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_load_from_save
*/

#include "player.h"
#include "components/quest/quest.h"
#include <unistd.h>
#include <fcntl.h>

static inventory_t *player_load_inventory_from_save(int fd)
{
    inventory_t *list = NULL;
    int id = 0;
    int nbr = 0;

    while (read(fd, &id, sizeof(int)) == sizeof(int) &&
    read(fd, &nbr, sizeof(int)) == sizeof(int)) {
        rpg_inventory_add_item(&list, nbr, id);
    }
    return (list);
}

player_t *player_load_from_save_fd(int fd)
{
    player_t *player = player_create();
    ssize_t size = 0;

    if (player == NULL)
        return (NULL);
    else if (fd < 0) {
        player_destroy(player);
        return (NULL);
    }
    rpg_destroy_quest(&player->quest);
    size = read(fd, player, sizeof(player_t));
    if (size != sizeof(player_t)) {
        return (NULL);
    }
    rpg_quest_load_from_save(&player->quest);
    player->planet_conf = NULL;
    player->item_list = player_load_inventory_from_save(fd);
    return (player);
}

player_t *player_load_from_save_path(char *path)
{
    int fd = open(path, O_RDONLY);
    player_t *player = NULL;

    if (fd < 0)
        return (NULL);
    player = (player_load_from_save_fd(fd));
    close(fd);
    return (player);
}