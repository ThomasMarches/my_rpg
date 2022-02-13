/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_menu_draw_scene
*/

#include "my_game.h"
#include "my_rpg.h"

void rpg_main_menu_draw_scene(scene_t *scene, game_t *game,
sfRenderWindow *window)
{
    display_scene(scene, window);
    sfRenderWindow_display(window);
}