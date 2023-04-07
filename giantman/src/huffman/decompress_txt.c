/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** decompress_txt.c
*/

#include "../../include/prototype.h"

int create_struct_letters(text_t *text)
{
    int i = 0;
    text->char_list = malloc(sizeof(char_info_t *) * text->nb_letter);
    while (i < text->nb_letter) {
        text->char_list[i] = malloc(sizeof(char_info_t));
        if (text->char_list[i] == NULL)
            return 84;
        text->char_list[i]->value = text->text_buffer[i + 2];
        text->char_list[i]->occurrence = text->nb_letter - i;
        text->char_list[i]->binary_code = malloc(32);
        if (text->char_list[i]->binary_code == NULL)
            return 84;
        text->char_list[i]->binary_code[0] = '\0';
        i += 1;
    }
    return 0;
}

int compress_text_to_binary(text_t *text)
{
    int i = 0;
    int total_size = 8 * text->len_compressed_text;
    text->binary_text = malloc(total_size + 1);
    text->binary_text[0] = '\0';
    char *buffer = malloc(9);
    while (i < text->len_compressed_text) {
        unsigned char tmp_char = (unsigned char)text->compressed_text[i];
        dec_to_bin(tmp_char, &buffer);
        my_strcat(text->binary_text, buffer);
        i += 1;
    }
    free(buffer);
    return 0;
}

int decompress_txt(int ac, char **av)
{
    text_t *text = NULL;
    int error = init_text_struct(av, &text);
    if (error == -1)
        return 84;
    if (error == 1)
        return 0;
    compress_text_to_binary(text);
    if (huffmantree_create(text) == -1)
        return 84;
    free_text(text);
    return 0;
}
