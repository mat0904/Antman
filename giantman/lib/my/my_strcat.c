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
    while (*(src +i) != '\0'){
        *(dest + len + i) = *(src + i);
        i += 1;
    }
    *(dest + len + i) = '\0';
    return (dest);
}
