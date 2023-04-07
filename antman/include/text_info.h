/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** text_info
*/

#ifndef B_CPE_110_LYN_1_1_ANTMAN_ADRIEN_AUDIARD_TEXT_INFO_H
    #define B_CPE_110_LYN_1_1_ANTMAN_ADRIEN_AUDIARD_TEXT_INFO_H

    #include "prototype.h"

    typedef struct {
        int value;
        int occurrence;
        char *binary_code;
    } char_info_t;

    typedef struct {
        char_info_t **char_list;
        char *unique_char;
        int nb_letter;
        char *text_buffer;
        int len_text;
        char *binary_text;
        char zero_added;
    } text_t;

#endif
