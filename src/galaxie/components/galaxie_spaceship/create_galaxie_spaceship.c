/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_galaxie_spaceship
*/

#include "galaxie/galaxie_spaceship.h"
#include "components/get_from_config.h"
#include "player.h"

game_object_t *create_galaxie_spaceship_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    char *path = get_str_from_conf(js, "texture_path");
    game_object_t *object = NULL;
    player_t *player = game->player;
    sfIntRect box = {0, 0, 0, 0};

    if (path == NULL || !get_intrect_from_conf(js, &box, "box"))
        return (NULL);
    object = create_game_object(last, path, player->galaxie_dest, PLAYER);
    if (object == NULL)
        return (NULL);
    object->box = box;
    object->update = &galaxie_spaceship_update;
    object->extend = game->player;
    object->free_extend = &player_save;
    sfSprite_setOrigin(object->sprite, (sfVector2f) {object->box.width / 2,
    object->box.height / 2});
    object->move = (sfVector2f) {0, 0};
    return (object);
}