/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** display
*/

#include "../../include/prototype.h"

int display_line_tree(text_t *text, huffman_tree_t *huffman_tree)
{
    write(1, &text->nb_letter, 1);
    for (int i = 0; i < huffman_tree->len; i++) {
        write(1, &huffman_tree->huffman_list[i]->value, 1);
    }
}

/*
int display_list(huffman_tree_t *huffman_tree)
{
    for (int i = 0; i < huffman_tree->len; i++)
        my_put_nbr(huffman_tree->huffman_list[i]->occurrence);
}

int display_tree(node_t *node, int i)
{
    if (node == NULL)
        return 0;
    display_tree(node->left, i + 1);
    for (int j = 0; j < i * 3; j++)
        write(1, " ", 1);
    if (node->value == -1 || node->value == 32 || node->value == 10)
        my_put_nbr(node->value);
    else
        write(1, &node->value, 1);
    write(1, " - ", 3);
    my_put_nbr(node->occurrence);
    write(1, "\n", 1);
    display_tree(node->right, i + 1);
    return (0);
}

int display_compressed_unique_char(text_t *text, huffman_tree_t
*huffman_tree)
{
    int i = 0;
    char *tmp_path = malloc(32);
    tmp_path[0] = '\0';
    while (text->unique_char[i] != '\0') {
        get_letter_path(huffman_tree->root, tmp_path, -1, text->unique_char[i]);
        my_revstr(tmp_path);
        int compressed_letter = bin_to_dec(tmp_path);
        tmp_path[0] = '\0';
        i += 1;
    }
    free(tmp_path);
}

int display_compressed_text(text_t *text, huffman_tree_t *huffman_tree)
{
    int i = 0;
    char *tmp_path = malloc(32);
    tmp_path[0] = '\0';
    while (text->text_buffer[i] != '\0') {
        get_letter_path(huffman_tree->root, tmp_path, -1, text->text_buffer[i]);
        my_revstr(tmp_path);
        int compressed_letter = bin_to_dec(tmp_path);
        tmp_path[0] = '\0';
        i += 1;
    }
    free(tmp_path);
}*/
