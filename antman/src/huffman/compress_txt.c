/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** compress_txt
*/

#include "../../include/prototype.h"

int extract_unique_char(text_t *text)
{
    text->unique_char[0] = '\0';
    int i = 0;
    int count = 0;
    while (i < text->len_text) {
        if (is_in_array(text->unique_char, text->text_buffer[i]) == 0) {
            my_strappend(text->unique_char, text->text_buffer[i]);
            count += 1;
        }
        i += 1;
    }
    text->nb_letter = count;
    return count;
}

int create_struct_letters(text_t *text)
{
    int i = 0;
    text->char_list = malloc(sizeof(char_info_t*) * text->nb_letter);
    if (text->char_list == NULL)
        return 84;
    while (i < text->nb_letter) {
        text->char_list[i] = malloc(sizeof(char_info_t));
        if (text->char_list[i] == NULL)
            return 84;
        text->char_list[i]->value = text->unique_char[i];
        text->char_list[i]->occurrence = count_char(text->text_buffer,
                                                text->unique_char[i]);
        text->char_list[i]->binary_code = malloc(32);
        text->char_list[i]->binary_code[0] = '\0';
        i += 1;
    }
    return 0;
}

int compress_txt(int ac, char **av)
{
    text_t *text = NULL;
    int error = init_text_struct(av, &text);
    if (error == -1)
        return 84;
    if (error == 1)
        return 0;
    extract_unique_char(text);
    create_struct_letters(text);
    if (huffman(text) == -1)
        return 84;
    free_text(text);
    return 0;
}
