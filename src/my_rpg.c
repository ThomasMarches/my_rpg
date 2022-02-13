/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_rpg
*/


#include "define.h"
#include "conf_paths.h"
#include "my_rpg.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>

window_t *init_window(void)
{
    window_t *window = malloc(sizeof(window_t));

    if (window == NULL)
        return (NULL);
    window->width = WINDOW_WIDTH;
    window->height = WINDOW_HEIGHT;
    window->bits = WINDOW_BITS_PER_PIXEL;
    window->framerate = WINDOW_FRAMERATE;
    window->name = (char *)WINDOW_NAME;
    window->window = make_window(window, 7);
    set_window_icon(window->window, (char *) ICON_PATH);
    return (window);
}

int my_rpg(int argc, char **argv)
{
    game_t *game = init_game();
    int display = MAIN_MENU_SCENE;

    if (game == NULL)
        return (84);
    while (sfRenderWindow_isOpen(game->window->window) && display >= 0)
        display = scene_loop(game, CONF_PATHS[display]);
    destroy_game(game);
    return (0);
}

int check_params(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    else if (!my_strcmp(argv[1], (char *)USAGE_FLAG))
        return (1);
    else
        return (0);
}

int check_error(int argc, char **argv, char **env)
{
    bool has_display = false;
    int param = 0;

    for (int i = 0; env[i] != NULL; i++)
        if (my_strcmp(env[i], (char *)ENV_DISPLAY))
            has_display = true;
    if (has_display == false)
        return (84);
    param = check_params(argc, argv);
    if (param == 1) {
        write(1, USAGE, my_strlen(USAGE));
        return (0);
    }
    return (my_rpg(argc, argv));
}