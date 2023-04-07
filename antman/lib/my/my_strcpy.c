/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday06-mathieu.borel
** File description:
** my_strcpy.c
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (*(src + i) != '\0') {
        *(dest + i) = *(src + i);
        i += 1;
    }
    *(dest + i) = '\0';
    return (dest);
}

int my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    while (*(src + i) != '\0' && i < n) {
        *(dest + i) = *(src + i);
        i += 1;
    }
    *(dest + i) = '\0';
    return 0;
}
