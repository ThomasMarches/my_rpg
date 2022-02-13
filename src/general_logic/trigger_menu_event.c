/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** trigger_menu_event
*/

#include "my_game.h"
#include "my_rpg.h"
#include "conf_paths.h"

void trigger_in_game_menu(sfEvent event, game_t *game,
scene_t *scene, sfRenderWindow *window)
{
    sfKeyCode key = event.key.code;
    int display = IN_GAME_MENU_SCENE;

    if (key != sfKeyEscape)
        return;
    while (display != MAIN_MENU_SCENE && display != GALAXIE_SCENE && \
    display != -1 && sfRenderWindow_isOpen(game->window->window)) {
        if (display != IN_GAME_MENU_SCENE) {
            display = scene_loop(game, CONF_PATHS[display]);
            display = (display == MAIN_MENU_SCENE) ? \
            IN_GAME_MENU_SCENE : display;
        } else
            display = scene_loop(game, (const char *)
            "./config/in_game_menu.json");
    }
    scene->display = display;
}

void trigger_in_game_menu_village(sfEvent event, game_t *game,
scene_t *scene, sfRenderWindow *window)
{
    int display = scene->display;

    trigger_in_game_menu(event, game, scene, window);
    display = scene->display;
    display = (display == GALAXIE_SCENE) ? VILLAGE_SCENE : display;
    display = (display == MAIN_MENU_SCENE) ? GALAXIE_SCENE : display;
    scene->display = display;
}