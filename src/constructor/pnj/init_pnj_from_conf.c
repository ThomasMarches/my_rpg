/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_pnj_from_conf.c
*/

#include "components/pnj/pnj.h"
#include "my_game.h"
#include "my_json.h"
#include "components/get_from_config.h"

static void rpg_pnj_init_box_and_pos(game_object_t *object,
sfVector2f pos)
{
    object->pos.x = pos.x;
    object->pos.y = pos.y;
    object->box.left = object->pos.x;
    object->box.top = object->pos.y;
    object->box.height = 84;
    object->box.width = 50;
    sfSprite_setPosition(object->sprite, object->pos);
}

game_object_t *rpg_pnj_init_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    sfVector2f pos = {0, 0};
    game_object_t *object = create_game_object(last, get_str_from_conf(js, \
    "texture_path"), pos, PNJ);

    if (object == NULL)
        return (NULL);
    object->extend = (void *)
    rpg_pnj_init_extend_from_conf(object, js, game, scene);
    object->free_extend = &rpg_pnj_destroy;
    if (!get_vector2f_from_conf(js, &pos, "pos") ||
    object->extend == NULL) {
        destroy_game_object(scene, object);
        return (NULL);
    }
    object->z_index = scene->z_index_deepth;
    object->draw = &rpg_draw_pnj;
    object->callback = &rpg_pnj_callback;
    rpg_pnj_init_box_and_pos(object, pos);
    return (object);
}