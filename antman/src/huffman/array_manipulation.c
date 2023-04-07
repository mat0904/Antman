/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** array_manipulation
*/

#include "../../include/prototype.h"

int is_in_array(char *array, char character)
{
    int i = 0;
    while (array[i] != '\0') {
        if (character == array[i]) {
            return 1;
        } else {
            i += 1;
        }
    }
    return 0;
}

int count_char(char *array, char character)
{
    int count = 0;
    int i = 0;
    while (array[i] != '\0') {
        if (character == array[i])
            count += 1;
        i += 1;
    }
    return count;
}
