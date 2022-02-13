/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_function
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "my_game.h"
#include "my_json.h"
#include "item/item_id.h"

typedef enum {
    WEAPON_ITEM,
    REPAIR_ITEM,
    QUEST_ITEM
} item_type;

typedef struct inventory {
    sfText *text[4];
    char *item_name;
    char *item_description;
    item_id id;
    item_type type;
    int item_number;
    bool selected;
    bool equiped;
    sfIntRect box;
    sfSprite *sprite;
    sfTexture *texture;
    int price;
    int damage;
    int repair_value;
    game_object_t *equip_button;
    struct inventory *next;
} inventory_t;

void free_item(inventory_t *item);
void rpg_inventory_remove_item(inventory_t *item, item_id id, int number);
void rpg_inventory_add_item(inventory_t **, int, item_id);
bool rpg_update_inventory(game_object_t *object, scene_t *scene);
bool rpg_inventory_get_click_on_item(game_object_t *object, void *pt);
void rpg_inventory_draw(sfRenderWindow *window, game_object_t *object);
void rpg_inventory_destroy(void *pt);
bool rpg_is_item_in_inventory(game_object_t *object, item_id id, int number);
void rpg_item_equip_weapon(scene_t *scene, inventory_t *item, \
inventory_t *list);
inventory_t *rpg_inventory_set_item_type(inventory_t *item, \
json_object_t *js);
inventory_t *rpg_item_create_text(inventory_t *item);
void free_text(sfText *text);
void rpg_item_update_text(inventory_t *item);

#endif /* !INVENTORY_H_ */