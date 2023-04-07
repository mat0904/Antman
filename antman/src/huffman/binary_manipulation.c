/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** binary_manipulation
*/

#include "../../include/prototype.h"

int power(int number, int exponent)
{
    int i = 0;
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return number;
    int result_number = number;
    while (i < exponent - 1) {
        result_number *= number;
        i++;
    }
    return result_number;
}

int bin_to_dec(char *binary)
{
    int decimal_result = 0;
    int i = my_strlen(binary) - 1;
    int j = 0;
    while (i >= 0) {
        decimal_result += ((binary[i] - 48) * power(2, j));
        i--;
        j++;
    }
    return decimal_result;
}

int dec_to_bin(int number, char **buffer)
{
    int save_nb = number;
    int len_binary = 0;
    while (save_nb > 0) {
        save_nb /= 2;
        len_binary += 1;
    }
    *buffer = malloc(len_binary + 1);
    *buffer[0] = '\0';
    while (number > 0) {
        my_strappend(*buffer, number % 2 + 48);
        number /= 2;
    }
    my_revstr(*buffer);
    int i = 0;
    char *new_buffer = NULL;
    while (*buffer[i] == 48)
        i += 1;
    new_buffer = buffer[i];
    *buffer = new_buffer;
    return 0;
}
