/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** free
*/

#include "../../include/prototype.h"

int free_text(text_t *text)
{
    free(text->binary_text);
    free(text->unique_char);
    free(text->read_buffer);
    free(text);
    return 0;
}

int free_huffman_tree(huffman_tree_t *huffman_tree)
{
    free(huffman_tree->huffman_list);
    free_huffman_root(huffman_tree->root);
    free(huffman_tree);
}

int free_huffman_root(node_t *node)
{
    if (node->left != NULL)
        free_huffman_root(node->left);
    if (node->right != NULL)
        free_huffman_root(node->right);
    free(node);
    return (0);
}
