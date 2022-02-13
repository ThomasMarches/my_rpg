/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_get_buff
*/

#include "my_json.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int json_buff_len(char *buff)
{
    int i = 0;

    if (buff == NULL)
        return (0);
    for (; buff[i] != '\0'; i++);
    return (i);
}

static char *json_cat_to_buff(char *buff, char *tmp_buff)
{
    char *new_buff = NULL;
    int buff_len = json_buff_len(buff);

    new_buff = malloc(sizeof(char) * (buff_len + 2));
    if (!new_buff)
        return (buff);
    for (int i = 0; i < buff_len; new_buff[i] = buff[i], i++);
    new_buff[buff_len] = *tmp_buff;
    new_buff[buff_len + 1] = '\0';
    if (buff)
        free(buff);
    return (new_buff);
}

void json_get_buff_compute_char(char **buff, char *tmp)
{
    static bool in_string = false;

    if (*tmp == '"')
        in_string = !in_string;
    if (in_string == true || (*tmp != ' ' && *tmp != '\t' && *tmp != '\n'))
        *buff = json_cat_to_buff(*buff, tmp);
}

char *json_get_buff(int fd)
{
    char *buff = NULL;
    char tmp[1] = "\0";

    while (read(fd, tmp, 1) > 0)
        json_get_buff_compute_char(&buff, tmp);
    return (buff);
}