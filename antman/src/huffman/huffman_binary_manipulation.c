/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** huffman_binary_manipulation
*/

#include "../../include/prototype.h"

int complete_binary_code(text_t *text, huffman_tree_t *huffman_tree)
{
    int i = 0;
    char *tmp_buffer = malloc(32);
    if (tmp_buffer == NULL)
        return 84;
    tmp_buffer[0] = '\0';
    while (i < text->nb_letter) {
        get_letter_path(huffman_tree->root, tmp_buffer, -1,
                        text->unique_char[i]);
        my_revstr(tmp_buffer);
        my_strcat(text->char_list[i]->binary_code, tmp_buffer);
        tmp_buffer[0] = '\0';
        i += 1;
    }
    free(tmp_buffer);
    return 0;
}

int concat_binary_buffer(text_t *text, huffman_tree_t *huffman_tree, int i,
                            int j)
{
    if (text->unique_char[j] == text->text_buffer[i]) {
        my_strcat(text->binary_text, text->char_list[j]->binary_code);
    }
}

int create_binary_text(text_t *text, huffman_tree_t *huffman_tree)
{
    int len = text->nb_letter * CHARACTER_SIZE;
    int i = 0;
    int j;
    while (i < text->len_text) {
        j = 0;
        while (j < text->nb_letter) {
            concat_binary_buffer(text, huffman_tree, i, j);
            j += 1;
        }
        i += 1;
    }
    len = my_strlen(text->binary_text);
    int complete = CHARACTER_SIZE - (len + CHARACTER_SIZE) % CHARACTER_SIZE;
    i = 0;
    while (i < complete) {
        my_strappend(text->binary_text, 48);
        i += 1;
    }
    text->zero_added = i + 48;
    return 0;
}
