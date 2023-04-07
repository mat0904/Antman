/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** init_ressources
*/

#include "../../include/prototype.h"

int extract_text(char **av, text_t *text)
{
    int BUF_SIZE = get_filesize(av);
    if (BUF_SIZE == 0)
        return 0;
    if (BUF_SIZE == -1)
        return -1;
    int fd = open(av[1], O_RDONLY);
    if (errno != 0)
        return -1;
    text->text_buffer = malloc(BUF_SIZE + 1);
    text->unique_char = malloc(BUF_SIZE + 1);
    int read_size = read(fd, text->text_buffer, BUF_SIZE);
    text->text_buffer[BUF_SIZE] = '\0';
    close(fd);
    return read_size;
}

int init_text_struct(char **av, text_t **text)
{
    *text = malloc(sizeof(text_t));
    if (*text == NULL)
        return -1;
    (*text)->char_list = NULL;
    (*text)->nb_letter = 0;
    (*text)->text_buffer = NULL;
    (*text)->len_text = extract_text(av, *text);
    if ((*text)->len_text == -1)
        return -1;
    if ((*text)->len_text == 0)
        return 1;
    (*text)->binary_text = malloc((*text)->len_text * CHARACTER_SIZE);
    if ((*text)->binary_text == NULL)
        return -1;
    (*text)->binary_text[0] = '\0';
    return 0;
}
