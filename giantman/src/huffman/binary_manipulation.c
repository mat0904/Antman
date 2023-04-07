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
    int size = 0;
    int count = 0;
    *buffer[0] = '\0';
    while (number > 0) {
        count += 1;
        my_strappend(*buffer, number % 2 + 48);
        size += 1;
        number /= 2;
    }
    while (count < 8) {
        my_strappend(*buffer, '0');
        count += 1;
    }
    my_revstr(*buffer);
    return size;
}
