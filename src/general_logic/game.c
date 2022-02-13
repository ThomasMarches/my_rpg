/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game
*/

#include "my_game.h"
#include "my_rpg.h"
#include "player.h"
#include "components/window/window_constructor.h"
#include <stdlib.h>
#include <SFML/Audio.h>
#include "components/quest/quest.h"

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    player_t *player = player_load_from_save_path("save/save");

    if (game == NULL)
        return (NULL);
    player = (player) ? player : player_create();
    if (player == NULL)
        return (NULL);
    game->player = player;
    game->window = create_window_from_conf("./config/window.json");
    if (game->window == NULL)
        return (NULL);
    return (game);
}

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window->window);
    free(game->window->name);
    free(game->window);
    player_destroy(game->player);
    free(game);
}