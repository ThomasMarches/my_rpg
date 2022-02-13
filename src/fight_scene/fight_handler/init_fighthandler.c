/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fighthandler.c
*/

#include "my_game.h"
#include "my_json.h"
#include "fight_scene/fight_handler.h"
#include <stdlib.h>

static sfIntRect rpg_fight_handler_button_init_box(game_object_t *object)
{
    sfIntRect box = {0, 0, 0, 0};

    if (object == NULL)
        return (box);
    box.left = object->pos.x;
    box.top = object->pos.y;
    box.height = 100;
    box.width = 200;
    return (box);
}

static fight_handler_t *rpg_fight_handler_init_button(fight_handler_t \
*handler, scene_t *scene)
{
    game_object_t *button = create_game_object(NULL, "templates/attack.png", \
    (sfVector2f) {25, 700}, ATTACK_BUTTON);

    if (button == NULL)
        return (NULL);
    button->box = rpg_fight_handler_button_init_box(button);
    button = create_game_object(button, "templates/repair.png", \
    (sfVector2f) {25, 800}, REPAIR_BUTTON);
    if (button == NULL)
        return (NULL);
    button->box = rpg_fight_handler_button_init_box(button);
    button = create_game_object(button, "templates/dodge.png", \
    (sfVector2f) {25, 900}, DODGE_BUTTON);
    if (button == NULL)
        return (NULL);
    button->box = rpg_fight_handler_button_init_box(button);
    handler->button = button;
    return (handler);
}

static fight_handler_t *rpg_fight_handler_init_extend(game_object_t *object, \
scene_t *scene)
{
    fight_handler_t *handler = malloc(sizeof(fight_handler_t));

    if (handler == NULL || object == NULL)
        return (NULL);
    handler->in_fight = 1;
    handler->player_turn = 1;
    handler->done = 0;
    handler->action_number = 3;
    handler->id = malloc(sizeof(action_id) * handler->action_number);
    if (handler->id == NULL)
        return (NULL);
    for (int x = 0; x != handler->action_number; x++)
        handler->id[x] = EMPTY;
    handler = rpg_fight_handler_init_button(handler, scene);
    if (rpg_fight_log_init(handler) == 0)
        return (NULL);
    return (handler);
}

game_object_t *rpg_fight_handler_create_from_conf(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = create_game_object(last, \
    "templates/fight_handler.png", (sfVector2f) {0, 0}, FIGHT_HANDLER);

    if (object == NULL)
        return (NULL);
    object->update = &rpg_fight_handler_update;
    object->draw = &rpg_fight_handler_draw;
    object->callback = &rpg_fight_handler_callback;
    object->box.left = object->pos.x;
    object->box.top = object->pos.y;
    object->box.height = 1920;
    object->box.width = 1080;
    object->extend = (void *) rpg_fight_handler_init_extend(object, scene);
    object->free_extend = &rpg_fight_handler_free_extend;
    if (object == NULL || object->extend == NULL) {
        rpg_fight_handler_free_extend((fight_handler_t *) object->extend);
        destroy_game_object(scene, object);
        return (NULL);
    }
    return (object);
}