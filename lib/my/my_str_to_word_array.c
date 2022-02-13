/*
** EPITECH PROJECT, 2019
** word
** File description:
** array
*/

#include "my.h"
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

int delimitation_string(char character, char *limit)
{
    for (int x = 0; limit[x]; x++)
        if (character == limit[x])
            return (-1);
    return (0);
}

int get_words_size(char *string, int cntr, char *limit)
{
    int size = 0;

    for (; delimitation_string(string[cntr], limit) == 0 && string[cntr];
    size++, cntr++);
    return (size);
}

int delimitation_loop(char const *string, int nbr, char *limit)
{
    if (delimitation_string(string[nbr], limit) == -1) {
        for (; delimitation_string(string[nbr], limit) == -1; nbr++);
        nbr = nbr - 1;
    }
    return (nbr);
}

int words_counting(char const *string, char *limit)
{
    int result = 1;

    for (int counter = 0; string[counter]; counter++, result += 1)
        counter = delimitation_loop(string, counter, limit);
    return (result);
}

char **my_str_to_word_array(char *string, char *limit)
{
    int nbr = 0, j = 0, x = 0;
    char **table_string = NULL;
    int words_number = words_counting(string, limit) + 2;

    table_string = malloc(sizeof(char *) * words_number + 1);
    for (; string[x];) {
        nbr = 0;
        for (; (delimitation_string(string[x], limit) == -1 && string[x]); x++);
        table_string[j] =
        malloc(sizeof(char) * (get_words_size(string, x, limit) + 1));
        for (; delimitation_string(string[x], limit) == 0 && string[x];
        x++, nbr++)
            table_string[j][nbr] = string[x];
        table_string[j][nbr] = '\0';
        j++;
        for (; (delimitation_string(string[x], limit) == -1 && string[x]); x++);
    }
    table_string[j] = NULL;
    free(string);
    return (table_string);
}