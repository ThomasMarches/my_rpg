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
#include "stdio.h"

void isolate_item(inventory_t *item, inventory_t *item_to_isolate)
{
    inventory_t *tmp = item;

    if (item == item_to_isolate)
        item = item_to_isolate->next;
    else {
        for (; tmp && tmp->next != item_to_isolate; tmp = tmp->next);
        if (tmp)
            tmp->next = item_to_isolate->next;
    }
}

void rpg_inventory_remove_item(inventory_t *item, item_id id, int number)
{
    inventory_t *tmp = NULL;

    for (tmp = item; tmp; tmp = tmp->next) {
        if (tmp->id == id && tmp->item_number >= number)
            tmp->item_number -= number;
        if (tmp->id == id && tmp->item_number == 0) {
            isolate_item(item, tmp);
            free_item(tmp);
        }
    }
}