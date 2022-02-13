/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_text_from_conf.c
*/

#include "my_json.h"
#include "my_game.h"
#include "components/text_handler/text_handler.h"
#include "components/get_from_config.h"
#include "components/decor/decor_constructor.h"
#include <stdlib.h>

static void rpg_text_handler_init(game_object_t *object)
{
    init_game_object(object);
    object->type = TEXT_HANDLER;
    object->draw = &rpg_text_handler_draw;
}

game_object_t *rpg_create_text_handler_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = NULL;
    sfVector2f pos = {0, 0};

    if (!get_vector2f_from_conf(js, &pos, "pos"))
        return (NULL);
    object = malloc(sizeof(game_object_t));
    if (object == NULL)
        return (NULL);
    rpg_text_handler_init(object);
    object->extend = (void *)
    rpg_text_handler_create_extend_from_conf(object, js, pos);
    object->pos = pos;
    object->next = last;
    if (object == NULL || object->extend == NULL) {
        destroy_game_object(scene, object);
        rpg_text_handler_destroy(object->extend);
        return (NULL);
    }
    object->free_extend = &rpg_text_handler_destroy;
    return (object);
}