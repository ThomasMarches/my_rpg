/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** open_inventory.c
*/

#include "my_json.h"
#include "components/get_from_config.h"
#include "my_game.h"
#include "item/inventory.h"

void open_inventory(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window)
{
    game_object_t *tmp = scene->objects_list;

    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        for (; tmp && tmp->type != INVENTORY; tmp = tmp->next);
        if (tmp == NULL)
            return;
        if (tmp->state == 0)
            tmp->state = 1;
        else
            tmp->state = 0;
    }
}
