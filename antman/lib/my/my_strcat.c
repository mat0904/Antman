/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-myls-mathieu.borel
** File description:
** my_strcat.c
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int i = 0;
    int y = 0;
    while (*(src + y) != '\0'){
        *(dest + y + len) = *(src + y);
        y += 1;
    }
    *(dest + y + len) = '\0';
    return (dest);
}
