/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** huffmantree_manipulation
*/

#include "../../include/prototype.h"

int get_letter_path(node_t *node, char *buffer, int node_index, char character)
{
    if (node == NULL)
        return 0;
    if (node->value == character) {
        my_strappend(buffer, node_index + 48);
        return 1;
    }
    if (get_letter_path(node->left, buffer, 0, character) == 1) {
        if (node_index != -1)
            my_strappend(buffer, node_index + 48);
        return 1;
    }
    if (get_letter_path(node->right, buffer, 1, character) == 1) {
        if (node_index != -1)
            my_strappend(buffer, node_index + 48);
        return 1;
    }
}
