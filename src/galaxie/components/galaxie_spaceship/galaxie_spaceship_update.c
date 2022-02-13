/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_spaceship_update
*/

#include "galaxie/galaxie_spaceship.h"
#include "galaxie/galaxie_hud.h"
#include "player.h"
#include "my.h"
#include <math.h>

static void galaxie_player_in_zone_fight(game_object_t *object,
scene_t *scene)
{
    player_t *player = scene->game->player;
    step_t *actual = get_quest_actual_step(&player->quest);
    sfIntRect fight_zone;

    if (actual == NULL || actual->step_type != FIGHT)
        return;
    fight_zone = (sfIntRect) {actual->pos.x - 100, actual->pos.y - 100,
    200, 200};
    if (sfIntRect_contains(&fight_zone, object->pos.x, object->pos.y))
        scene->display = FIGHT_SCENE;
}

static void galaxie_set_galaxie_conf(game_object_t *object,
game_object_t *planet)
{
    player_t *player = object->extend;
    sfFloatRect box = sfSprite_getGlobalBounds(object->sprite);
    sfFloatRect planet_box = sfSprite_getGlobalBounds(planet->sprite);

    if (sfFloatRect_intersects(&box, &planet_box, NULL)) {
        my_free(player->planet_conf);
        player->planet_conf = my_strdup(planet->extend);
    }
}

static void galaxie_planet_test_collide_with_planet(game_object_t *object,
scene_t *scene)
{
    game_object_t *hud = scene->objects_list;
    sfFloatRect box = sfSprite_getGlobalBounds(object->sprite);
    sfFloatRect planet_box = {0, 0, 0, 0};

    for (; hud && hud->type != GALAXIE_HUD; hud = hud->next);
    if (!hud)
        return;
    hud->state = 0;
    for (game_object_t *tmp = scene->objects_list; tmp; tmp = tmp->next) {
        if (tmp->type == PLANET) {
            planet_box = sfSprite_getGlobalBounds(tmp->sprite);
            hud->state = (sfFloatRect_intersects(&box, &planet_box, NULL)) ?
            galaxie_hud_move(hud, tmp) : hud->state;
            galaxie_set_galaxie_conf(object, tmp);
        }
    }
}

bool galaxie_spaceship_update(game_object_t *object, scene_t *scene)
{
    float angle = 0;

    galaxie_player_in_zone_fight(object, scene);
    galaxie_spaceship_move(object, scene);
    player_check_end(object, scene);
    if (object->move.x == 0 && object->move.y == 0)
        return (true);
    angle = atan2(object->move.y, object->move.x) * (180.0 / M_PI) + 90;
    sfSprite_setRotation(object->sprite, angle);
    galaxie_planet_test_collide_with_planet(object, scene);
    return (true);
}