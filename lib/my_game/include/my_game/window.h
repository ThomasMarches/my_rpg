/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** window
*/

#ifndef WINDOW_H_
#define WINDOW_H_

#include <SFML/Graphics.h>

typedef struct window_s {
    int width;
    int height;
    int bits;
    int framerate;
    char *name;
    int style;
    sfRenderWindow *window;
} window_t;

sfRenderWindow *make_window(window_t *, int);
window_t *init_window(void);
void set_window_icon(sfRenderWindow *, char *);

#endif /* !WINDOW_H_ */
