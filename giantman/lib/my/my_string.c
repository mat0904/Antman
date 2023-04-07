/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-yohann.mangenot
** File description:
** my_string
*/

#include "../../include/my_lib.h"
#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int len_str = my_strlen(str);
    int loop_i = len_str / 2;
    char k;
    for (int i = 0; i < loop_i; i++) {
        k = *(str + i);
        *(str + i) = *(str + (len_str - i - 1));
        *(str + (len_str - i - 1)) = k;
    }
    return (str);
}

char *my_strappend(char *dest, char src)
{
    int i = my_strlen(dest);
    *(dest + i) = src;
    *(dest + i + 1) = '\0';
    return (dest);
}
