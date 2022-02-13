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
#include "player.h"
#include <stdio.h>

static void rpg_inventory_set_item_pos(inventory_t *tmp, sfVector2f pos, \
sfVector2f tmp2)
{
    for (int x = 0, y = 0; tmp; tmp = tmp->next, x++) {
        x = (x == 11) ? 0 : x;
        y = (x == 0) ? y + 1 : y;
        tmp2 = (sfVector2f) {275 + (x * 60) + pos.x, 190 + (y * 60) + pos.y};
        tmp->box = (sfIntRect) {tmp2.x, tmp2.y, 50, 50};
        sfSprite_setPosition(tmp->sprite, tmp2);
        sfSprite_setPosition(tmp->equip_button->sprite,
        (sfVector2f) {1350 + pos.x, 700 + pos.y});
        tmp->equip_button->box.left = 1350 + pos.x;
        tmp->equip_button->box.top = 700 + pos.y;
        tmp2.x = 1240 + pos.x;
        sfText_setPosition(tmp->text[0], (sfVector2f) {tmp2.x, 120 + pos.y});
        sfText_setPosition(tmp->text[1], (sfVector2f) {tmp2.x, 300 + pos.y});
        sfText_setPosition(tmp->text[2], (sfVector2f) {tmp2.x, 550 + pos.y});
    }
}

bool rpg_update_inventory(game_object_t *object, scene_t *scene)
{
    inventory_t *tmp = *((inventory_t **) object->extend);
    sfVector2f tmp2 = {275, 250};
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(scene->window));

    pos = (sfVector2f) {pos.x - 1920 / 2, pos.y - 1080 / 2};
    sfSprite_setPosition(object->sprite, (sfVector2f) {pos.x, pos.y});
    object->box.left = pos.x + 250;
    object->box.top = pos.y + 215;
    if (object->state == 0)
        return (true);
    rpg_inventory_set_item_pos(tmp, pos, tmp2);
    return (true);
}

bool rpg_inventory_get_click_on_item(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *) pt;
    sfVector2f pos = get_mouse_exact_pos(scene->window);
    inventory_t *tmp = NULL;
    int x = pos.x;
    int y = pos.y;

    for (tmp = *((inventory_t **) object->extend); tmp; tmp = tmp->next) {
        if (sfIntRect_contains(&tmp->box, x, y)) {
            tmp->selected = 1;
        } else if (tmp->type == WEAPON_ITEM && tmp->selected == 1 && \
        sfIntRect_contains(&tmp->equip_button->box, x, y)) {
            rpg_item_equip_weapon(scene, tmp, *((inventory_t **)
            object->extend));
            tmp->selected = 1;
        } else
            tmp->selected = 0;
    }
    return (false);
}

void rpg_inventory_draw(sfRenderWindow *window, game_object_t *object)
{
    inventory_t *tmp = NULL;

    if (object->state == 0)
        return;
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
    for (tmp = *((inventory_t **) object->extend); tmp; tmp = tmp->next) {
        if (tmp->type == WEAPON_ITEM && tmp->equip_button->texture != NULL && \
        tmp->equip_button->sprite != NULL && tmp->selected == 1)
            sfRenderWindow_drawSprite(window, tmp->equip_button->sprite, NULL);
        if (tmp->texture != NULL && tmp->sprite != NULL \
        && tmp->selected == 1) {
            sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
            sfRenderWindow_drawText(window, tmp->text[0], NULL);
            sfRenderWindow_drawText(window, tmp->text[1], NULL);
            sfRenderWindow_drawText(window, tmp->text[2], NULL);
            sfRenderWindow_drawText(window, tmp->text[3], NULL);
        } else if (tmp->texture != NULL && tmp->sprite != NULL)
            sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
    }
}

game_object_t *rpg_inventory_create_from_conf(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = create_game_object(last, get_str_from_conf(js, \
    "texture_path"), (sfVector2f) {0, -50}, INVENTORY);
    player_t *player = game->player;

    if (object == NULL)
        return (NULL);
    object->draw = &rpg_inventory_draw;
    object->callback = &rpg_inventory_get_click_on_item;
    object->update = &rpg_update_inventory;
    object->box = (sfIntRect) {0, 0, 1920, 1080};
    object->z_index = scene->z_index_deepth;
    object->extend = &player->item_list;
    return (object);
}