/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** my_putstr.c
*/

#include "my.h"
#include <unistd.h>

void my_putstr(char *string)
{
    write(1, string, my_strlen(string));
}