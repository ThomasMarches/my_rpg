/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** default_event
*/

#include "my_game/event.h"
#include "my_game.h"

void close_scene(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

sfVector2f get_mouse_exact_pos(sfRenderWindow *window)
{
    sfVector2i false_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f true_pos = {0, 0};
    const sfView *view = sfRenderWindow_getView(window);

    true_pos = sfRenderWindow_mapPixelToCoords(window, false_pos, view);
    return (true_pos);
}

void is_click_on_object(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window)
{
    game_object_t *object = scene->objects_list;
    sfMouseButtonEvent mouse_button = event.mouseButton;
    sfVector2f pos = get_mouse_exact_pos(game->window->window);
    int x = pos.x;
    int y = pos.y;
    bool stop = false;

    if (mouse_button.button != sfMouseLeft)
        return;
    for (; object && !stop; object = object->next) {
        if (object->callback != NULL && sfIntRect_contains(&object->box, x, y))
            stop = object->callback(object, scene);
    }
}

void handle_resize(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window)
{

}