/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** huffman_tree
*/

#ifndef B_CPE_110_LYN_1_1_ANTMAN_ADRIEN_AUDIARD_HUFFMAN_TREE_H
    #define B_CPE_110_LYN_1_1_ANTMAN_ADRIEN_AUDIARD_HUFFMAN_TREE_H

    #include "prototype.h"

    typedef struct node{
        int value;
        int occurrence;
        struct node *left;
        struct node *right;
    } node_t;

    typedef struct {
        node_t **huffman_list;
        node_t *root;
        int len;
    } huffman_tree_t;

#endif
