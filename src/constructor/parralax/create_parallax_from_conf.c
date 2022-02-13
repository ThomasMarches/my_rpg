/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_parallax_from_conf
*/

#include "my_game.h"
#include "my_json.h"
#include "components/parallax/parallax.h"
#include "components/get_from_config.h"

game_object_t *rpg_create_parallax_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    char *path = get_str_from_conf(js, "texture_path");
    sfVector2f pos = {0, 0};
    game_object_t *object = NULL;

    if (path == NULL || !get_vector2f_from_conf(js, &pos, "pos"))
        return (NULL);
    object = create_game_object(last, path, pos, DECOR);
    if (object == NULL)
        return (NULL);
    init_appearing_object(object);
    object->update = &rpg_update_parallax;
    return (object);
}