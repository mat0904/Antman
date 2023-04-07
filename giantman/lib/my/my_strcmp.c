/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday06-mathieu.borel
** File description:
** my_strcmp.c
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);
    int total_len = 0;
    if (len_s1 < len_s2) {
        total_len = len_s2;
    } else {
        total_len = len_s1;
    }
    for (int i = 0; i < total_len; i++) {
        if (*(s1 + i) != *(s2 + i)) {
            return (*(s1 + i) - *(s2 + i));
        }
    }
    return (0);
}

int my_strstrictcmp(char const *s1, char const *s2)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);
    int total_len = 0;
    if (len_s1 > len_s2)
        total_len = len_s1;
    else
        total_len = len_s2;
    for (int i = 0; i < total_len; i++) {
        if (s1[i] != s2[i])
            return (0);
    }
    return (1);
}
