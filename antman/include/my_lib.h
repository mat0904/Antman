/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-bsmyls-mathieu.borel
** File description:
** prototype.h
*/

#ifndef MY_LIB_H_
    #define MY_LIB_H_

    int my_getnbr(char const *str);
    int my_put_nbr(int nb);
    int my_strcmp(char const *s1, char const *s2);
    int my_strstrictcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    int my_strncpy(char *dest, char const *src, int n);
    char *my_revstr(char *str);
    char *my_strappend(char *dest, char src);
    int my_putstr(char const *str);
    int my_putchar(char c);
    int my_strlen(char const *str);
    int nbsize(int nb);
    char *my_strdup(char const *str);
    char *my_strcat(char *dest, char const *src);

#endif
