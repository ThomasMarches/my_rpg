/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_shop.c
*/

#include "item/shop.h"
#include "my_game.h"
#include <stdlib.h>

shop_t *rpg_init_shop(char *path)
{
    shop_t *shop = malloc(sizeof(shop_t));

    if (shop == NULL)
        return (NULL);
    return (shop);
}

game_object_t *rpg_shop_create(game_object_t *last, char *sprite_path, \
char *settings_path)
{
    game_object_t *object = create_game_object(last, sprite_path, \
    (sfVector2f) {0, 0}, SHOP);

    if (object == NULL)
        return (NULL);
    object->extend = (shop_t *) rpg_init_shop(settings_path);
    if ((shop_t *) object->extend == NULL)
        return (NULL);
    return (object);
}