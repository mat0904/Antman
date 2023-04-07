/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** prototype
*/

#ifndef B_CPE_110_LYN_1_1_ANTMAN_ADRIEN_AUDIARD_PROTOTYPE_H
    #define B_CPE_110_LYN_1_1_ANTMAN_ADRIEN_AUDIARD_PROTOTYPE_H

    #include "include.h"

    //antman.c
    int antman(int, char **);

    //free.c
    int free_text(text_t *);
    int free_huffman_list(huffman_tree_t *);

    //init_ressources.c
    int extract_text(char **, text_t *);
    int init_text_struct(char **, text_t **);

    //array_manipulation.c
    int is_in_array(char *, char);
    int count_char(char *, char);

    //huffman.c
    int huffman(text_t *);

    //node_quicksort.c
    int quick_sort(node_t **, int, int);

    int display_line_tree(text_t *text, huffman_tree_t *huffman_tree);
    //display.c
    /*int display_list(huffman_tree_t *);
    int display_tree(node_t *, int);
    int display_compressed_text(text_t *, huffman_tree_t *);
    int display_compressed_unique_char(text_t *, huffman_tree_t *);*/

    //huffmantree_manipulation.c
    int get_letter_path(node_t *, char *, int, char);

    //binary_manipulation.c
    int power(int, int);
    int bin_to_dec(char *);
    int dec_to_bin(int, char **);

    //huffman_binary_manipulation.c
    int complete_binary_code(text_t *, huffman_tree_t *);
    int create_binary_text(text_t *, huffman_tree_t *);

    //compress_ppm.c
    int my_getnbr_ppm(char *, int *);
    void get_occurence(rgb_t *, char *, int *, int *);
    void pixel_struct(result_t *, buffer_t *, int);

    //init_buffer.c
    int extract_buffer(char **, buffer_t *);
    int init_buffer_struct(char **, buffer_t **);

    //init_pixel_struct.c
    int get_nb_pixel(buffer_t *, int );
    pixel_t *init_pixel(buffer_t *, int *);

    //print_result_ppm.c
    void print_occ_pixel(result_t *, rgb_t *, int *);
    void print_ppm(result_t *, pixel_t *);

    //write_src_and_cmp.c
    void write_src(result_t *, int *, int);
    int src_cmp(char *, char *, int);

#endif
