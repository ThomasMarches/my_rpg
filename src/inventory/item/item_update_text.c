/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_inventory.c
*/

#include "components/get_from_config.h"
#include "item/inventory.h"
#include "my.h"
#include "font/font.h"
#include <stdlib.h>

void rpg_item_update_text(inventory_t *item)
{
    char *number = my_strcat_nbr("Number: ", item->item_number);

    if (number == NULL)
        return;
    if (item->text[2] != NULL) {
        free_text(item->text[2]);
        item->text[2] = init_text(number, 1240, 500, (char *) FONT_PATH[0]);
    }
    free(number);
}