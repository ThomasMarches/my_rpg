/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my
*/

#include <stdarg.h>

#ifndef MY_H_
#define MY_H_

char *my_strdup(char const *);
char *my_nbr_to_str(long long int);
int my_strlen(const char *);
char *my_strcat(char *, char *);
int my_strcmp(char *, char *);
int my_getnbr(char const *);
char **my_str_to_word_array(char *string, char *limit);
void my_putstr(char *string);
char *my_strndup(char *str, int n);
void my_free(void *pt);
char *my_strcat_nbr(char *dest, int n);

#endif /* !MY_H_ */
