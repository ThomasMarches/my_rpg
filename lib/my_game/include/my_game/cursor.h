/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** cursor
*/

#ifndef CURSOR_H_
#define CURSOR_H_

#include <SFML/Graphics.h>

typedef struct cursor {
    sfSprite *sprite;
    sfTexture *texture;
    sfBool displayed;
    int width;
    int height;
} cursor_t;

void draw_cursor(cursor_t, sfRenderWindow *);
cursor_t init_cursor(char *);

#endif /* !CURSOR_H_ */
