/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** create_huffman_tree
*/

#include "../../include/prototype.h"

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

int init_node(text_t *text, huffman_tree_t *huffman_tree)
{
    int i = 0;
    int j = text->nb_letter - 1;
    while (i < text->nb_letter) {
        huffman_tree->len += 1;
        huffman_tree->huffman_list[i] = malloc(sizeof(node_t));
        node_t *tmp_node = huffman_tree->huffman_list[i];
        tmp_node->left = NULL;
        tmp_node->right = NULL;
        tmp_node->occurrence = j;
        tmp_node->value = text->unique_char[i];
        i += 1;
        j -= 1;
    }
    finish_huffman_tree(huffman_tree);
}
