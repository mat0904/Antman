/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** huffman
*/

#include "../../include/prototype.h"



int detect_char_path(text_t *text, huffman_tree_t *huffman_tree, int *i, int j)
{
    node_t *tmp_node = huffman_tree->root;
    for (int k = *i; k <= j; k++) {
        switch (text->binary_text[k]) {
            case 48:
                tmp_node = tmp_node->left;
                break;
            case 49:
                tmp_node = tmp_node->right;
                break;
        }
        if (tmp_node->value != 0) {
            write(1, &tmp_node->value, 1);
            tmp_node = huffman_tree->root;
            *i = j + 1;
            return 0;
        }
    }
    return 0;
}

int detect_char_fromhuffman(text_t *text, huffman_tree_t *huffman_tree)
{
    int i = 0;
    node_t *tmp_node = huffman_tree->root;
    int len = my_strlen(text->binary_text) - text->zero_added;
    while (i <= len) {
        if (tmp_node->value != -1) {
            write(1, &tmp_node->value, 1);
            tmp_node = huffman_tree->root;
        }
        if (text->binary_text[i] == 48) {
            tmp_node = tmp_node->left;
            i += 1;
        } else {
            tmp_node = tmp_node->right;
            i += 1;
        }
    }
    return 0;
}

int huffmantree_create(text_t *text)
{
    huffman_tree_t *huffman_tree = malloc(sizeof(huffman_tree_t));
    if (huffman_tree == NULL)
        return -1;
    huffman_tree->huffman_list = malloc(sizeof(node_t *) * text->nb_letter);
    huffman_tree->len = 0;
    init_node(text, huffman_tree);
    huffman_tree->root = huffman_tree->huffman_list[0];
    detect_char_fromhuffman(text, huffman_tree);
    free_huffman_tree(huffman_tree);
    return 0;
}
