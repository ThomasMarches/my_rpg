/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_text_extend_from_conf
*/

#include "components/text_handler/text_handler.h"
#include "components/get_from_config.h"
#include <stdlib.h>

static void rpg_load_text_handler_color_from_conf(json_object_t *js,
text_handler_t *text)
{
    sfColor color;

    if (!get_color_from_conf(js, &color, "color"))
        return;
    text->color = color;
    sfText_setColor(text->text, text->color);
}

static void rpg_load_text_handler_character_size_from_conf(json_object_t *js,
text_handler_t *text)
{
    int size = text->character_size;

    if (!get_int_from_conf(js, &size, "size")) {
        sfText_setCharacterSize(text->text, text->character_size);
        return;
    }
    text->character_size = size;
    sfText_setCharacterSize(text->text, text->character_size);
}

static void rpg_load_text_handler_style_from_conf(json_object_t *js,
text_handler_t *text)
{
    sfTextStyle style = sfTextRegular;
    int tmp = 0;

    if (!get_int_from_conf(js, &tmp, "style")) {
        sfText_setStyle(text->text, style);
        return;
    }
    style |= (tmp & sfTextBold) ? sfTextBold : sfTextRegular;
    style |= (tmp & sfTextItalic) ? sfTextItalic : sfTextRegular;
    style |= (tmp & sfTextUnderlined) ? sfTextUnderlined : sfTextRegular;
    style |= (tmp & sfTextStrikeThrough) ? sfTextStrikeThrough : sfTextRegular;
    sfText_setStyle(text->text, style);
}

static bool rpg_load_text_handler_text_and_font_from_conf(json_object_t *js,
text_handler_t *text)
{
    char *string = get_str_from_conf(js, "string");
    char *font = get_str_from_conf(js, "font");

    if (!font || !string)
        return (false);
    text->font = sfFont_createFromFile(font);
    if (text->font == NULL)
        return (false);
    sfText_setFont(text->text, text->font);
    sfText_setString(text->text, string);
    return (true);
}

text_handler_t *rpg_text_handler_create_extend_from_conf(game_object_t *object,
json_object_t *js, sfVector2f pos)
{
    text_handler_t *text = malloc(sizeof(text_handler_t));

    if (text == NULL)
        return (NULL);
    *text = (text_handler_t) {NULL, NULL, 11, sfBlack, sfTextRegular};
    text->text = sfText_create();
    if (text->text == NULL ||
    !rpg_load_text_handler_text_and_font_from_conf(js, text)) {
        rpg_text_handler_destroy((void *) text);
        return (NULL);
    }
    sfText_setPosition(text->text, pos);
    rpg_load_text_handler_character_size_from_conf(js, text);
    rpg_load_text_handler_style_from_conf(js, text);
    rpg_load_text_handler_color_from_conf(js, text);
    return (text);
}