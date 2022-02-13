/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_space_ship.c
*/

#include "my.h"
#include "components/get_from_config.h"
#include "fight_scene/ship.h"
#include "fight_scene/fight_handler.h"
#include "font/font.h"
#include "player.h"
#include <stdlib.h>

void rpg_space_ship_destroy_tmp_text(char *tmp1, char *tmp2, char *tmp3)
{
    if (tmp1)
        free(tmp1);
    if (tmp2)
        free(tmp2);
    if (tmp3)
        free(tmp3);
}

static space_ship_t *rpg_space_ship_init_text(space_ship_t *ship)
{
    char *tmp1 = my_strcat_nbr("Your life: ", ship->hp);
    char *tmp2 = my_strcat_nbr("Your shield: ", ship->shield);
    char *tmp3 = my_strcat_nbr("Actions left: ", ship->member_in_ship);

    if (tmp1 == NULL || tmp2 == NULL || tmp3 == NULL) {
        rpg_space_ship_destroy_tmp_text(tmp1, tmp2, tmp3);
        return (NULL);
    }
    ship->action_left = init_text(tmp3, 275, 750, (char *) FONT_PATH[0]);
    ship->repair_turn_left = init_text("Repair statue: Unable", \
    275, 800, (char *) FONT_PATH[0]);
    ship->hp_text = init_text(tmp1, 275, 850, (char *) FONT_PATH[0]);
    ship->shield_text = init_text(tmp2, 275, 900, (char *) FONT_PATH[0]);
    rpg_space_ship_destroy_tmp_text(tmp1, tmp2, tmp3);
    return (ship);
}

static space_ship_t *rpg_space_ship_extend_create_from_conf(game_object_t \
*object, json_object_t *js, scene_t *scene)
{
    space_ship_t *space_ship = malloc(sizeof(space_ship_t));

    if (space_ship == NULL)
        return (NULL);
    space_ship->repair_statue = 0;
    space_ship->in_fight = 1;
    space_ship->member_in_ship = 3;
    if (!get_int_from_conf(js, (int *) &space_ship->equiped_weapon, \
    "weapon_id") || !get_int_from_conf(js, &space_ship->damage, "damage") ||
    !get_int_from_conf(js, &space_ship->hp, "hp") ||
    !get_int_from_conf(js, &space_ship->repair_value, "repair_value") ||
    !get_int_from_conf(js, &space_ship->shield, "shield"))
        return (NULL);
    space_ship->max_hp = space_ship->hp;
    space_ship = rpg_space_ship_init_text(space_ship);
    return (space_ship);
}

game_object_t *rpg_space_ship_create_from_conf(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = create_game_object(last, get_str_from_conf(js, \
    "texture_path"), (sfVector2f) {0, 0}, SPACESHIP);

    if (object == NULL)
        return (NULL);
    if (!get_vector2f_from_conf(js, &object->pos, "pos"))
        return (NULL);
    sfSprite_setPosition(object->sprite, object->pos);
    sfSprite_setRotation(object->sprite, 90);
    object->draw = &rpg_space_ship_draw;
    object->update = &rpg_spaceship_update;
    object->extend = (void *) \
    rpg_space_ship_extend_create_from_conf(object, js, scene);
    object->free_extend = &rpg_space_ship_destroy;
    if (object == NULL || object->extend == NULL) {
        rpg_space_ship_destroy((space_ship_t *) object->extend);
        destroy_game_object(scene, object);
        return (NULL);
    }
    return (object);
}

game_object_t *rpg_space_ship_create(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    player_t *player = game->player;
    json_object_t *config = json_create_from_file(
    player->quest.step->fight_scene);
    json_value_t *value = NULL;
    game_object_t *object = NULL;

    if (config == NULL)
        return (NULL);
    value = json_get_element_by_key(config, "player");
    if (value == NULL || value->value_type != OBJECT) {
        json_object_destroy(config);
        return (NULL);
    }
    object = rpg_space_ship_create_from_conf(last, value->value, game, scene);
    json_object_destroy(config);
    return (object);
}