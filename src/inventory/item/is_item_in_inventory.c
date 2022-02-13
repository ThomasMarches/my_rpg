/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_inventory.c
*/

#include "my_json.h"
#include "components/get_from_config.h"
#include "my_game.h"
#include "item/inventory.h"

bool rpg_is_item_in_inventory(game_object_t *object, item_id id, int number)
{
    game_object_t *tmp = NULL;
    inventory_t *item =  NULL;

    if (object == NULL)
        return (false);
    for (tmp = object; tmp && tmp->type != INVENTORY; tmp = tmp->next);
    if (tmp->type != INVENTORY)
        return (false);
    for (item = (inventory_t *) object->extend; item; item = item->next)
        if (item->id == id && item->item_number >= number)
            return (true);
    return (false);
}