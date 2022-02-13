/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fight_log.c
*/

#include "fight_scene/fight_handler.h"
#include "my.h"
#include <stdlib.h>

void rpg_fight_log_push_text(fight_handler_t *handler, char *string, \
int number)
{
    char *tmp = NULL;
    char *save[4];

    if (number == 0)
        tmp = my_strcat(string, " ");
    else
        tmp = my_strcat_nbr(string, number);
    if (tmp == NULL)
        return;
    for (int x = 4, i = 0; x > 0 && i < 5; x--, i++)
        save[i] = (char *) sfText_getString(handler->fight_log[x]);
    for (int x = 3, i = 0; x >= 0; x--, i++)
        sfText_setString(handler->fight_log[x], save[i]);
    sfText_setString(handler->fight_log[4], tmp);
    free(tmp);
}