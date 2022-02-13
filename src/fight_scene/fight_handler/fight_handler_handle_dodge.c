/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fighthandler.c
*/

#include "my_game.h"
#include <unistd.h>
#include <stdlib.h>
#include "fight_scene/fight_handler.h"

int rpg_fight_handler_dodge_handle(scene_t *scene, int number, int x)
{
    int num = (rand() % (100 - 0 + 1)) + 0;

    if (num < number * 10) {
        if (x == 0) {
            rpg_fight_log_push_text(rpg_fight_handler_get_extend(scene), \
            "Your ennemy dodged one of your attack.", 0);
        } else {
            rpg_fight_log_push_text(rpg_fight_handler_get_extend(scene), \
            "You dodged one of the ennemy's attack.", 0);
        }
        return (1);
    }
    return (0);
}