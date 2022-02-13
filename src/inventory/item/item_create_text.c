/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_inventory.c
*/

#include "item/inventory.h"
#include "my.h"
#include "font/font.h"
#include <stdlib.h>

inventory_t *rpg_item_create_text(inventory_t *item)
{
    char *name = my_strcat("Name: ", item->item_name);
    char *number = my_strcat_nbr("Number: ", item->item_number);

    if (item == NULL || name == NULL || number == NULL)
        return (NULL);
    item->text[0] = init_text(name, 1240, 70, (char *) FONT_PATH[0]);
    item->text[1] = init_text(item->item_description, 1240, 250, (char *) \
    FONT_PATH[0]);
    item->text[2] = init_text(number, 1240, 500, (char *) FONT_PATH[0]);
    free(name);
    free(number);
    if (!item->text[0] && !item->text[1] && item->text[2])
        return (NULL);
    return (item);
}