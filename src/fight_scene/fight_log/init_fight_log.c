/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fight_log.c
*/

#include "my_game.h"
#include "const.h"
#include "fight_scene/fight_handler.h"
#include "font/font.h"

void rpg_fight_log_destroy(fight_handler_t *handler)
{
    if (handler == NULL)
        return;
    for (int i = 0; i < 5; i++)
        free_text(handler->fight_log[i]);
}

int rpg_fight_log_init(fight_handler_t *handler)
{
    if (handler == NULL)
        return (0);
    for (int i = 0, y = 720; i < 5; i++, y += 50) {
        handler->fight_log[i] = init_text(" ", 1425, y, (char *)FONT_PATH[1]);
        if (handler->fight_log[i] == NULL) {
            rpg_fight_log_destroy(handler);
            return (0);
        }
        sfText_setCharacterSize(handler->fight_log[i], 25);
    }
    return (1);
}