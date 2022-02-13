/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_free
*/

#include <stdlib.h>

void my_free(void *pt)
{
    if (pt != NULL)
        free(pt);
}