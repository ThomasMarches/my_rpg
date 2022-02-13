/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_handler_ennemy_fight_functions
*/

#include "fight_scene/ennemy.h"
#include <stdlib.h>

void rpg_fight_handler_repair_ennemy(game_object_t *object, scene_t *scene)
{
    ennemy_t *ennemy = rpg_ennemy_get_extend(scene);

    if (ennemy == NULL)
        return;
    if (ennemy->repair_value + ennemy->hp > ennemy->max_hp) {
        rpg_fight_log_push_text(rpg_fight_handler_get_extend(scene), \
        "Your ennemy repaired of ", ennemy->max_hp - ennemy->hp);
        ennemy->hp = ennemy->max_hp;
    } else {
        rpg_fight_log_push_text(rpg_fight_handler_get_extend(scene), \
        "Your ennemy repaired of ", ennemy->repair_value);
        ennemy->hp += ennemy->repair_value;
    }
    ennemy->repair_statue = 0;
}

void rpg_fight_handler_remove_ennemy_life(game_object_t *object, \
scene_t *scene)
{
    ennemy_t *ennemy = rpg_ennemy_get_extend(scene);
    int damage = rpg_spaceship_get_damage(object, scene);

    if (ennemy == NULL || damage == 0)
        return;
    else if (rpg_fight_handler_dodge_handle(scene, ennemy->dodge_value, 0) == 1)
        return;
    rpg_fight_log_push_text(rpg_fight_handler_get_extend(scene), \
    "You attacked your ennemy for ", damage);
    if (ennemy->shield + ennemy->hp <= damage)
        ennemy->hp = 0;
    else if (ennemy->shield >= damage)
        ennemy->shield -= damage;
    else {
        if (ennemy->hp > damage - ennemy->shield) {
            ennemy->hp -= damage - ennemy->shield;
            ennemy->shield = 0;
        }
    }
}

static void rpg_fight_handler_ennemy_clear_actions(ennemy_t *ennemy, \
scene_t *scene)
{
    for (int x = 0; x != ennemy->action_number; x++)
        ennemy->id[x] = EMPTY;
    ennemy->repair_statue++;
}

void rpg_fight_handler_make_ennemy_play(game_object_t *object, scene_t *scene)
{
    ennemy_t *ennemy = rpg_ennemy_get_extend(scene);

    if (ennemy == NULL)
        return;
    ennemy->dodge_value = 0;
    for (int x = 0, num = 0; x != ennemy->action_number; x++) {
        num = (rand() % (100 - 0 + 1)) + 0;
        if (num <= 66 && num > 33 && ennemy->repair_statue >= 3 && \
        ennemy->hp < ennemy->max_hp)
            rpg_fight_handler_repair_ennemy(object, scene);
        else if (num < 100 && num > 66)
            ennemy->dodge_value++;
        else
            rpg_fight_handler_remove_spaceship_life(object, scene);
    }
    rpg_fight_handler_ennemy_clear_actions(ennemy, scene);
}