/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** init_ressources
*/

#include "../../include/prototype.h"

int extract_unique_letter(text_t *text)
{
    int offset = 1;
    text->nb_letter = (unsigned char)text->compressed_text[0];
    text->zero_added = text->compressed_text[text->nb_letter + 1] - 48;
    text->unique_char = malloc(text->nb_letter);
    text->unique_char[0] = '\0';
    int i = 0;
    while (i < text->nb_letter) {
        text->unique_char[i] = text->compressed_text[i + offset];
        i += 1;
    }
    return 0;
}

int extract_compressed_text(char **av, text_t *text)
{
    int BUF_SIZE = get_filesize(av);
    if (BUF_SIZE == -1)
        return -1;
    if (BUF_SIZE == 0)
        return 1;
    int fd = open(av[1], O_RDONLY);
    if (errno != 0)
        return -1;
    text->compressed_text = malloc(BUF_SIZE + 2);
    text->read_buffer = text->compressed_text;
    int read_size = read(fd, text->compressed_text, BUF_SIZE + 1);
    text->len_compressed_text = read_size;
    text->compressed_text[read_size] = '\0';
    extract_unique_letter(text);
    int offset = 2 + text->nb_letter;
    text->len_compressed_text -= (offset);
    text->compressed_text = &text->compressed_text[offset];
    close(fd);
    return read_size;
}

int init_text_struct(char **av, text_t **text)
{
    *text = malloc(sizeof(text_t));
    if (*text == NULL)
        return -1;
    int error = extract_compressed_text(av, *text);
    if (error == -1)
        return -1;
    if (error == 1)
        return 1;
    return 0;
}
