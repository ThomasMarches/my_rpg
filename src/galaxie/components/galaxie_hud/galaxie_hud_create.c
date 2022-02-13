/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_hud_create
*/

#include "galaxie/galaxie_hud.h"
#include <stdlib.h>

static void galaxie_hud_init_object(game_object_t *object, game_object_t *last)
{
    init_game_object(object);
    object->draw = &galaxie_hud_draw;
    object->update = &galaxie_hud_update;
    object->free_extend = &galaxie_hud_destroy;
    object->next = last;
    object->type = GALAXIE_HUD;
}

static void galaxie_hud_init_extend(galaxie_hud_t *hud, scene_t *scene,
json_object_t *js, game_t *game)
{
    json_value_t *value = NULL;

    *hud = (galaxie_hud_t) {NULL, NULL, NULL, NULL, scene};
    value = json_get_element_by_key(js, "button");
    hud->button = (value && value->value_type == OBJECT) ?
    rpg_create_animated_button_from_conf(NULL, value->value, game, scene) :
    NULL;
    value = json_get_element_by_key(js, "text");
    hud->planet_name = (value && value->value_type == OBJECT) ?
    rpg_create_text_handler_from_conf(NULL, value->value, game, scene) : NULL;
    hud->village_conf_path = NULL;
    hud->scene = scene;
    value = json_get_element_by_key(js, "player_pos");
    hud->player_pos = (value && value->value_type == OBJECT) ?
    rpg_create_text_handler_from_conf(NULL, value->value, game, scene) : NULL;
}

game_object_t *galaxie_hud_create(game_object_t *last, json_object_t *js,
game_t *game, scene_t *scene)
{
    game_object_t *object = malloc(sizeof(game_object_t));
    galaxie_hud_t *hud = malloc(sizeof(galaxie_hud_t));

    if (object == NULL || hud == NULL)
        return (NULL);
    galaxie_hud_init_object(object, last);
    galaxie_hud_init_extend(hud, scene, js, game);
    if (hud->planet_name == NULL || hud->button == NULL)
        return (NULL);
    object->z_index = 1;
    object->extend = hud;
    return (object);
}