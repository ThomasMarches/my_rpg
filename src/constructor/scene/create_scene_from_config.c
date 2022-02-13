/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_scene_from_config
*/

#include "my_game.h"
#include "my_json.h"
#include "my_rpg.h"
#include "components/scene/scene_constructor.h"

static scene_t *create_scene_from_json_object(json_object_t *js, \
game_t *game)
{
    scene_t *scene = create_empty_scene(game);

    if (scene == NULL)
        return (NULL);
    sfRenderWindow_setMouseCursorVisible(scene->window, sfTrue);
    scene->z_index_deepth = load_scene_z_index_deepth_from_config(js);
    scene->display = load_scene_id_from_config(js);
    load_scene_draw_from_config(js, scene);
    load_scene_update_from_config(js, scene);
    scene->objects_list = \
    load_scene_objects_list_from_config(js, game, scene);
    if (scene->display < 0 || scene->z_index_deepth < 0 || \
    scene->objects_list == NULL || scene->draw_scene == NULL || \
    scene->update_scene == NULL || \
    !load_scene_background_color_from_config(js, scene) || \
    !load_scene_event_from_config(js, scene)) {
        destroy_scene(scene);
        return (NULL);
    }
    return (scene);
}

scene_t *create_scene_from_file(const char *path, game_t *game)
{
    json_object_t *js = json_create_from_file((char *) path);
    scene_t *scene = NULL;
    const sfView *view = sfRenderWindow_getView(game->window->window);

    if (js == NULL)
        return (NULL);
    scene = create_scene_from_json_object(js, game);
    json_object_destroy(js);
    if (!scene)
        return (NULL);
    if (view) {
        sfView_setSize((sfView *) view, (sfVector2f) {game->window->width,
        game->window->height});
        sfView_setCenter((sfView *) view, (sfVector2f) {game->window->width / 2,
        game->window->height / 2});
        sfRenderWindow_setView(scene->window, view);
    }
    return (scene);
}