/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** node_quicksort
*/

#include "../../include/prototype.h"

int partitionning_sort(node_t **huffman_list, int first, int last)
{
    int pivot = huffman_list[last]->occurrence;
    int index = first;
    int i = first;
    node_t *tmp = NULL;
    while (i < last) {
        if (huffman_list[i]->occurrence >= pivot) {
            tmp = huffman_list[index];
            huffman_list[index] = huffman_list[i];
            huffman_list[i] = tmp;
            index += 1;
        }
        i++;
    }
    tmp = huffman_list[index];
    huffman_list[index] = huffman_list[last];
    huffman_list[last] = tmp;
    return index;
}

int quick_sort(node_t **huffman_list, int first, int last)
{
    int pivot;
    if (first < last) {
        pivot = partitionning_sort(huffman_list, first, last);
        quick_sort(huffman_list, first, pivot - 1);
        quick_sort(huffman_list, pivot + 1, last);
    }
    return 0;
}
