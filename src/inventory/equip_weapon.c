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
#include <stdio.h>

void rpg_item_update_sprite(inventory_t *tmp, char *path)
{
    sfSprite_destroy(tmp->equip_button->sprite);
    sfTexture_destroy(tmp->equip_button->texture);
    tmp->equip_button->sprite = sfSprite_create();
    tmp->equip_button->texture = \
    sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(tmp->equip_button->sprite, \
    tmp->equip_button->texture, sfTrue);
    sfSprite_setPosition(tmp->equip_button->sprite, (sfVector2f) {1350, 700});
}

void rpg_item_equip_weapon(scene_t *scene, inventory_t *item, \
inventory_t *list)
{
    for (inventory_t *tmp = list; tmp; tmp = tmp->next) {
        if (tmp->equiped == 1) {
            tmp->equiped = 0;
            rpg_item_update_sprite(tmp, "templates/menu/equip.png");
        }
    }
    item->equiped = 1;
    rpg_item_update_sprite(item, "templates/menu/equiped.png");
}