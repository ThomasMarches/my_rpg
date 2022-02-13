/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_inventory.c
*/

#include "components/get_from_config.h"
#include "item/inventory.h"
#include <stdlib.h>

inventory_t *rpg_inventory_set_item_type(inventory_t *item, \
json_object_t *js)
{
    if (!get_int_from_conf(js, (int *) &item->type, "item_type")) {
        free(item);
        return (NULL);
    }
    if (item->type == WEAPON_ITEM && !get_int_from_conf(js, \
    &item->damage, "damage")) {
        free(item);
        return (NULL);
    }
    if (item->type == REPAIR_ITEM && !get_int_from_conf(js, \
    &item->repair_value, "repair_value")) {
        free(item);
        return (NULL);
    }
    return (item);
}