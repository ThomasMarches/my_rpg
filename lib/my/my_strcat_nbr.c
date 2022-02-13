/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_strcat_nbr
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat_nbr(char *dest, int n)
{
    int length = 0;
    int length_dest = 0;
    char *str = NULL;
    char *src = my_nbr_to_str(n);

    if (src == NULL)
        return (NULL);
    length = my_strlen(src);
    length_dest = my_strlen(dest);
    str = malloc(sizeof(char) * (length + length_dest) + 1);
    for (int h = 0; h != length + length_dest + 1; h = h + 1)
        str[h] = 0;
    for (int j = 0; j < length_dest; j++)
        str[j] = dest[j];
    for (int i = 0; i < length; i++)
        str[length_dest  + i] = src[i];
    free(src);
    return (str);
}