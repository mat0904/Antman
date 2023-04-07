/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** free
*/

#include "../../include/prototype.h"

int free_text(text_t *text)
{
    int i = 0;
    while (i < text->nb_letter) {
        free(text->char_list[i]->binary_code);
        free(text->char_list[i]);
        i += 1;
    }
    free(text->binary_text);
    free(text->char_list);
    free(text->text_buffer);
    free(text->unique_char);
    free(text);
    return 0;
}

int free_huffman_root(node_t *node)
{
    if (node == NULL)
        return 0;
    node_t *node_left = node->left;
    node_t *node_right = node->right;
    free(node);
    free_huffman_root(node_left);
    free_huffman_root(node_right);
    return (0);
}

int free_huffman_list(huffman_tree_t *huffman_tree)
{
    free_huffman_root(huffman_tree->root);
    free(huffman_tree->huffman_list);
    free(huffman_tree);
}
