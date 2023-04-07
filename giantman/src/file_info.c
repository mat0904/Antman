/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** file_info
*/

#include "../include/prototype.h"

int get_filesize(char **av)
{
    int fd = open(av[1], O_RDONLY);
    int BUF_SIZE = 32;
    char *buffer = malloc(BUF_SIZE + 1);
    int size = 0;
    int read_size = 0;
    while ((read_size = read(fd, buffer, BUF_SIZE)) != 0) {
        if (read_size == -1)
            return -1;
        size += read_size;
    }
    free(buffer);
    close(fd);
    return size;
}
