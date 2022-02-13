/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** text
*/

#ifndef TEXT_H_
#define TEXT_H_

#include <SFML/Graphics.h>

sfText *init_text(char *, int, int, char *);
void update_text(sfText *, sfColor, sfVector2f, int);
void center_text(sfText *, int);

#endif /* !TEXT_H_ */
