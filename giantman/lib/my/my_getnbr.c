/*
** EPITECH PROJECT, 2022
** dev_function
** File description:
** my_getnbr.c
*/

#include "../../include/my_lib.h"

int is_int(char const character)
{
    char digits_char[] = "0123456789";
    for (int i = 0; i < 10; i++) {
        if (digits_char[i] == character)
            return (1);
    }
    return (0);
}

int get_int(char const character)
{
    char digits_char[] = "0123456789";
    int digits_int[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 10; i++) {
        if (digits_char[i] == character)
            return (digits_int[i]);
    }
    return (0);
}

int count_sign(char const *str, int *is_negative)
{
    int i = 0;
    int count_minus = 0;
    char digits_char[] = "0123456789";
    while (is_int(*(str + i)) != 1 && *(str + i) != '\0') {
        if (*(str + i) != '-' && *(str + i) != '+' && is_int(*(str + i)) == 0)
            return (-1);
        if (*(str + i) == '-') {
            count_minus += 1;
        }
        i++;
    }
    if ((count_minus % 2) == 0) {
        *is_negative = 0;
    } else {
        *is_negative = 1;
    }
    return (i);
}

int calc(char const *str, int is_negative, int start)
{
    int total_number = 0;
    int i = start;
    while (is_int(*(str + i)) == 1 && *(str + i) != '\0') {
        total_number = ((total_number + get_int(*(str + i))) * 10);
        i++;
    }
    if (is_negative == 0) {
        return (total_number);
    } else {
        return (total_number * -1);
    }
}

int my_getnbr(char const *str)
{
    int is_negative = 0;
    int len = my_strlen(str);
    if (is_int(str[0]) == 1) {
        return (calc(str, 0, 0) / 10);
    } else {
        int start = count_sign(str, &is_negative);
        if (start != -1)
            return (calc(str, is_negative, start) / 10);
        return (0);
    }

}
