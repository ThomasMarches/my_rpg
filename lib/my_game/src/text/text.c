/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** text
*/

#include "my_game/text.h"
#include <stdlib.h>

void center_text(sfText *text, int window_width)
{
    int width = sfText_getGlobalBounds(text).width;
    sfVector2f pos = sfText_getPosition(text);

    pos.x = (window_width - width) / 2;
    sfText_setPosition(text, pos);
}

void update_text(sfText *text, sfColor color, sfVector2f pos, int size)
{
    sfText_setColor(text, color);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
}

sfText *init_text(char *str, int x, int y, char *font_path)
{
    sfVector2f vector = {x, y};
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(font_path);

    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, 32);
    sfText_setPosition(text, vector);
    sfText_setColor(text, sfWhite);
    sfText_setStyle(text, sfTextBold);
    return (text);
}