/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include "my_json.h"
#include "my_game.h"
#include "item/inventory.h"
#include "components/quest/quest.h"

typedef struct {
    sfVector2f galaxie_dest;
    inventory_t *item_list;
    quest_t quest;
    int money;
    char *planet_conf;
} player_t;

player_t *player_create(void);
player_t *player_load_from_save_path(char *path);
player_t *player_load_from_save_fd(int fd);
void player_save(void *pt);
void player_destroy(player_t *player);
void player_check_end(game_object_t *object, scene_t *scene);

#endif /* !PLAYER_H_ */
