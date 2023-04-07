/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** write_src_and_cmp.c
*/

#include "../../include/prototype.h"

void write_src(result_t *result, int *str, int n)
{
    char nospace = 128;
    if (n == 1) {
        result->res[result->i] = nospace;
        result->len += 1;
        result->i += 1;
    }
    result->res[result->i] = *str;
    result->len += 1;
    result->i += 1;
}

int src_cmp(char *buf, char *src, int i)
{
    int j = 0;
    int n = 0;
    for (; src[j] != '\0'; j++, i++) {
        if (buf[i] != src[j])
            return 0;
    }
    return j - 1;
}
