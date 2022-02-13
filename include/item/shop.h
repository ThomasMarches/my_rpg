/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_function
*/

#ifndef SHOP_H_
#define SHOP_H_

#include "my_game.h"

typedef struct shop {
    char *name;
    char **item_name;
    char **item_description;
    int *item_price;
    int *item_id;
    sfVector2f **item_pos;
    sfIntRect **item_rect;
    int number_of_items;
    void (*free_shop)(void *);
} shop_t;

#endif /* !SHOP_H_ */
