/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-myls-mathieu.borel
** File description:
** my_strdup.c
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);

char *my_strdup(char const *str)
{
    int len = my_strlen(str);
    char *str_cpy = malloc(len + 1);
    if (str_cpy == NULL){
        return (NULL);
    }
    my_strcpy(str_cpy, str);
    str_cpy[len] = '\0';
    return (str_cpy);
}
