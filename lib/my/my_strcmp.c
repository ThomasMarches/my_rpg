/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** compare str
*/

#include "my.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    for (; s2[i] != '\0' && s1[i] != '\0'; i++)
        if (s2[i] != s1[i])
            return (-1);
    if (i == my_strlen(s2))
        return (0);
    return (-1);
}