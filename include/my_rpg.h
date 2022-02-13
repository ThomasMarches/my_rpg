/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** my_runner
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "const.h"
#include "my_game.h"

typedef struct game_object game_object_t;

typedef enum {
    MAIN_MENU_SCENE,
    OPTION_SCENE,
    INFOS_SCENE,
    END_SCENE,
    IN_GAME_MENU_SCENE,
    GALAXIE_SCENE,
    FIGHT_SCENE,
    FIGHT_PAUSE_SCENE,
    VILLAGE_SCENE,
    IN_GAME_MENU_VILLAGE_SCENE,
    NULL_SCENE,
} scene_index;

game_t *init_game();
void destroy_game(game_t *);
int check_error(int, char **, char **);

#endif /* !MY_RUNNER_H_ */
