/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_ennemy.c
*/

#include "my.h"
#include "fight_scene/ennemy.h"
#include "components/get_from_config.h"
#include "font/font.h"
#include "player.h"
#include <stdlib.h>

static ennemy_t *rpg_ennemy_create_text(ennemy_t *ennemy)
{
    char *tmp1 = NULL;
    char *tmp2 = NULL;

    tmp1 = my_strcat_nbr("Ennemy's life: ", ennemy->hp);
    tmp2 = my_strcat_nbr("Ennemy's shield: ", ennemy->shield);
    if (tmp1 == NULL || tmp2 == NULL) {
        if (!tmp1)
            free(tmp1);
        if (!tmp2)
            free(tmp2);
        return (NULL);
    }
    ennemy->name_text = init_text(ennemy->name, 900, 750,
    (char *) FONT_PATH[0]);
    ennemy->hp_text = init_text(tmp1, 900, 800, (char *) FONT_PATH[0]);
    ennemy->shield_text = init_text(tmp2, 900, 850, (char *) FONT_PATH[0]);
    free(tmp1);
    free(tmp2);
    return (ennemy);
}

static ennemy_t *rpg_ennemy_extend_init(ennemy_t *ennemy)
{
    ennemy->action_number = 0;
    ennemy->id = NULL;
    ennemy->max_hp = 0;
    ennemy->name = NULL;
    ennemy->equiped_weapon = 0;
    ennemy->in_fight = 1;
    ennemy->repair_statue = 0;
    ennemy->dodge_value = 0;
    ennemy->damage = 0;
    ennemy->hp = 0;
    ennemy->shield = 0;
    ennemy->repair_value = 0;
    ennemy->repair_statue = 0;
    ennemy->hp_text = NULL;
    ennemy->quest_id = 0;
    ennemy->shield_text = NULL;
    return (ennemy);
}

static ennemy_t *rpg_ennemy_extend_create_from_conf(game_object_t *object, \
json_object_t *js)
{
    ennemy_t *ennemy = malloc(sizeof(ennemy_t));

    if (ennemy == NULL)
        return (NULL);
    ennemy = rpg_ennemy_extend_init(ennemy);
    if (!get_int_from_conf(js, (int *) &ennemy->equiped_weapon, "weapon_id") ||
    !get_int_from_conf(js, &ennemy->damage, "damage") ||
    !get_int_from_conf(js, &ennemy->hp, "hp") ||
    !get_int_from_conf(js, &ennemy->action_number, "action_number") ||
    !get_int_from_conf(js, (int *) &ennemy->quest_id, "quest_id") ||
    !get_int_from_conf(js, &ennemy->repair_value, "repair_value") ||
    !get_int_from_conf(js, &ennemy->shield, "shield") ||
    ((ennemy->name = get_str_from_conf(js, "name")) == NULL) ||
    (ennemy->id = malloc(sizeof(action_id) * ennemy->action_number)) == NULL)
        return (NULL);
    ennemy->max_hp = ennemy->hp;
    for (int x = 0; x != ennemy->action_number; x++)
        ennemy->id[x] = EMPTY;
    ennemy = rpg_ennemy_create_text(ennemy);
    return (ennemy);
}

game_object_t *rpg_ennemy_create_from_conf(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = create_game_object(last, get_str_from_conf(js, \
    "texture_path"), (sfVector2f) {0, 0}, ENNEMY);

    if (object == NULL)
        return (NULL);
    if (!get_vector2f_from_conf(js, &object->pos, "pos"))
        return (NULL);
    sfSprite_setPosition(object->sprite, object->pos);
    sfSprite_setRotation(object->sprite, 270);
    object->draw = &rpg_ennemy_draw;
    object->update = &rpg_ennemy_update;
    object->free_extend = &rpg_ennemy_destroy;
    object->extend = (void *) rpg_ennemy_extend_create_from_conf(object, js);
    if (object == NULL || object->extend == NULL) {
        rpg_ennemy_destroy(object->extend);
        destroy_game_object(scene, object);
        return (NULL);
    }
    return (object);
}

game_object_t *rpg_ennemy_create(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    player_t *player = game->player;
    step_t *step = get_quest_actual_step(&player->quest);
    json_object_t *config = json_create_from_file(step->fight_scene);
    json_value_t *value = NULL;
    game_object_t *object = NULL;

    if (config == NULL)
        return (NULL);
    value = json_get_element_by_key(config, "opponent");
    if (value == NULL || value->value_type != OBJECT) {
        json_object_destroy(config);
        return (NULL);
    }
    object = rpg_ennemy_create_from_conf(last, value->value, game, scene);
    json_object_destroy(config);
    return (object);
}

