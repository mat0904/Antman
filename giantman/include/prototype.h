/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** prototype
*/

#ifndef B_CPE_110_LYN_1_1_ANTMAN_ADRIEN_AUDIARD_PROTOTYPE_H
    #define B_CPE_110_LYN_1_1_ANTMAN_ADRIEN_AUDIARD_PROTOTYPE_H

    #include "include.h"

    //giantman.c
    int giantman(int, char **);

    //free.c
    int free_text(text_t *);
    int free_huffman_root(node_t *node);
    int free_huffman_tree(huffman_tree_t *huffman_tree);

    //create_huffman_tree.c
    int init_node(text_t *text, huffman_tree_t *huffman_tree);

    //extract_text.c
    int extract_compressed_text(char **, text_t *);
    int init_text_struct(char **, text_t **);

    //binary_manipulaiton.c
    int bin_to_dec(char *binary);
    int dec_to_bin(int number, char **buffer);

    //node_quicksort.c
    int quick_sort(node_t **, int, int);

    //huffman.c
    int huffmantree_create(text_t *text);
    int finish_huffman_tree(huffman_tree_t *);

    //init_buffer.c
    int extract_buffer(char **, buffer_t *);
    int init_buffer_struct(char **, buffer_t **);

    //decrompress_html.c
    void write_src(result_t *, char *, int);

#endif
