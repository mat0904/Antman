/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** init_ressources
*/

#include "../../include/prototype.h"

int extract_buffer(char **av, buffer_t *buffer)
{
    int BUF_SIZE = get_filesize(av);
    if (BUF_SIZE == -1)
        return -1;
    if (BUF_SIZE == 0)
        return 0;
    int fd = open(av[1], O_RDONLY);
    if (errno != 0)
        return -1;
    buffer->buf = malloc(BUF_SIZE + 1);
    int read_size = read(fd, buffer->buf, BUF_SIZE);
    buffer->buf[BUF_SIZE] = '\0';
    close(fd);
    return read_size;
}

int init_buffer_struct(char **av, buffer_t **buffer)
{
    *buffer = malloc(sizeof(buffer_t));
    if (*buffer == NULL)
        return 84;
    (*buffer)->buf = NULL;
    (*buffer)->len = extract_buffer(av, *buffer);
    if ((*buffer)->len == -1)
        return 84;
    return 0;
}
