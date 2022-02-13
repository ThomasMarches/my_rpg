/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_inventory.c
*/

#include "components/get_from_config.h"
#include "item/inventory.h"
#include "item/item_path.h"
#include "my.h"
#include "font/font.h"
#include <stdlib.h>

static inventory_t *rpg_inventory_create_text(inventory_t *item)
{
    char *name = my_strcat("Name: ", item->item_name);
    char *number = my_strcat_nbr("Number: ", item->item_number);
    char *tmp = NULL;
    if (item == NULL || name == NULL || number == NULL)
        return (NULL);
    if (item->type == WEAPON_ITEM) {
        tmp = my_strcat_nbr("Damage: ", item->damage);
        item->text[3] = init_text(tmp, 1240, 600, (char *) FONT_PATH[1]);
        free(tmp);
    } else if (item->type == REPAIR_ITEM) {
        tmp = my_strcat_nbr("Repair value: ", item->repair_value);
        item->text[3] = init_text(tmp, 1240, 600, (char *) FONT_PATH[1]);
        free(tmp);
    }
    item->text[0] = init_text(name, 1240, 70, (char *) FONT_PATH[0]);
    item->text[1] = init_text(item->item_description, 1240, 250, (char *) \
    FONT_PATH[1]);
    item->text[2] = init_text(number, 1240, 500, (char *) FONT_PATH[1]);
    free(name);
    free(number);
    if (!item->text[0] && !item->text[1] && item->text[2] && !item->text[3])
        return (NULL);
    return (item);
}

static inventory_t *rpg_inventory_init_item(inventory_t *item, \
json_object_t *js, int number)
{
    item->item_name = my_strdup(get_str_from_conf(js, "name"));
    item->item_description = my_strdup(get_str_from_conf(js, "description"));
    item->item_number = number;
    item->equiped = 0;
    item->selected = 0;
    if (item->type == WEAPON_ITEM) {
        item->equip_button = create_game_object(NULL,
        "templates/menu/equip.png", (sfVector2f) {1350, 700}, BUTTON);
        if (item->equip_button == NULL)
            return (NULL);
        item->equip_button->box = (sfIntRect) {1350, 700, 121, 266};
    }
    if (!get_int_from_conf(js, (int *) &item->id, "item_id") || \
    item->equip_button == NULL) {
        free(item);
        return (NULL);
    }
    return (item);
}

static void rpg_inventory_add_new_item_from_conf(inventory_t **list, \
char *path, int number)
{
    json_object_t *js = json_create_from_file(path);
    inventory_t *item = malloc(sizeof(inventory_t));

    if (js == NULL || item == NULL)
        return;
    item->next = *list;
    item->sprite = sfSprite_create();
    item->texture = sfTexture_createFromFile(get_str_from_conf(js, \
    "path"), NULL);
    if (item->sprite == NULL || item->texture == NULL)
        return;
    sfSprite_setTexture(item->sprite, item->texture, sfTrue);
    item = rpg_inventory_set_item_type(item, js);
    if (rpg_inventory_init_item(item, js, number) == NULL)
        return;
    item = rpg_inventory_create_text(item);
    item->box = (sfIntRect) {0, 0, 0, 0};
    json_object_destroy(js);
    *list = item;
}

void rpg_inventory_add_item(inventory_t **list, int number, item_id id)
{
    inventory_t *tmp = NULL;
    char *path = NULL;

    if (ITEM_PATHS[id] != NULL)
        path = (char *) ITEM_PATHS[id];
    for (tmp = *list; tmp; tmp = tmp->next) {
        if (tmp->id == id) {
            tmp->item_number += number;
            rpg_item_update_text(tmp);
        }
    }
    rpg_inventory_add_new_item_from_conf(list, \
    path, number);
}