/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy_music.c
*/

#include <stdlib.h>
#include "components/music_handler/music.h"
#include "SFML/Audio.h"

void rpg_music_handler_destroy_music(void *pt)
{
    music_handler_t *music_handler = NULL;

    if (pt == NULL)
        return;
    music_handler = (music_handler_t *) pt;
    if (music_handler->music != NULL) {
        sfMusic_stop(music_handler->music);
        sfMusic_destroy(music_handler->music);
    }
    free(music_handler);
}