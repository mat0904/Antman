/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** huffman
*/

#include "../../include/prototype.h"

int create_node(text_t *text, node_t **node, int i)
{
    *node = malloc(sizeof(node_t));
    if (*node == NULL)
        return -1;
    (*node)->occurrence = text->char_list[i]->occurrence;
    (*node)->value = text->char_list[i]->value;
    (*node)->left = NULL;
    (*node)->right = NULL;
    return 0;
}

int create_huffman_list(text_t *text, huffman_tree_t **huffman_tree)
{
    (*huffman_tree) = malloc(sizeof(huffman_tree_t));
    if ((*huffman_tree) == NULL)
        return -1;
    (*huffman_tree)->huffman_list = malloc(sizeof(node_t *) * text->nb_letter);
    (*huffman_tree)->len = text->nb_letter;
    int i = 0;
    while (i < text->nb_letter) {
        if (create_node(text, &(*huffman_tree)->huffman_list[i], i) == -1) {
            free((*huffman_tree));
            return -1;
        }
        i += 1;
    }
    quick_sort((*huffman_tree)->huffman_list, 0, (*huffman_tree)->len - 1);
    int j = 0;
    for (int i = (*huffman_tree)->len - 1; i >= 0; i--) {
        (*huffman_tree)->huffman_list[i]->occurrence = j;
        j += 1;
    }
    return 0;
}

int finish_huffman_tree(huffman_tree_t *huffman_tree)
{
    while (huffman_tree->len > 1) {
        int index = huffman_tree->len - 2;
        node_t *tmp_node = malloc(sizeof(node_t));
        if (tmp_node == NULL)
            return 84;
        tmp_node->value = -1;
        tmp_node->occurrence = huffman_tree->huffman_list[index]->occurrence
                    + huffman_tree->huffman_list[index + 1]->occurrence;
        tmp_node->left = huffman_tree->huffman_list[index + 1];
        tmp_node->right = huffman_tree->huffman_list[index];
        huffman_tree->huffman_list[index] = tmp_node;
        huffman_tree->len -= 1;
        quick_sort(huffman_tree->huffman_list, 0, huffman_tree->len - 1);
    }
}

int display_new_char(text_t *text, huffman_tree_t *huffman_tree)
{
    int len = my_strlen(text->binary_text) / CHARACTER_SIZE;
    char *copy = malloc(CHARACTER_SIZE + 1);
    if (copy == NULL)
        return 84;
    copy[0] = '\0';
    int i = 0;
    write(1, &text->zero_added, 1);
    while (i < len) {
        my_strncpy(copy, &text->binary_text[i * CHARACTER_SIZE],
                        CHARACTER_SIZE);
        unsigned char tmp_char = bin_to_dec(copy);
        write(1, &tmp_char, 1);
        copy[0] = '\0';
        i += 1;
    }
    free(copy);
    return 0;
}

int huffman(text_t *text)
{
    huffman_tree_t *huffman_tree = NULL;
    if (create_huffman_list(text, &huffman_tree) == -1)
        return -1;
    display_line_tree(text, huffman_tree);
    if (finish_huffman_tree(huffman_tree) == 84)
        return -1;
    huffman_tree->root = huffman_tree->huffman_list[0];
    complete_binary_code(text, huffman_tree);
    create_binary_text(text, huffman_tree);
    if (display_new_char(text, huffman_tree) == 84)
        return -1;
    free_huffman_list(huffman_tree);
    return 0;
}
