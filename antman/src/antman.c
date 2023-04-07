/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** antman
*/

#include "../include/prototype.h"

int antman(int ac, char **av)
{
    if (ac != 3)
        return 84;
    char buf[255];
    int type = my_getnbr(av[2]);
    switch (type) {
        case 1:
            return compress_txt(ac, av);
        case 2:
            return init_sources_html(ac, av);
        case 3:
            return compress_ppm(ac, av);
        default:
            return 84;
    }
}
