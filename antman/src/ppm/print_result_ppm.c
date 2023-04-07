/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** print_result_ppm.c
*/

#include "../../include/prototype.h"

void print_occ_pixel(result_t *result, rgb_t *rgb, int *rgba)
{
    rgb[*rgba].occurence -= 1;
    if (rgb[*rgba].occurence == -1) {
        (*rgba)++;
        write_src(result, &(rgb[*rgba].occurence), 0);
        write_src(result, &(rgb[*rgba].value), 0);
    }
}

void print_ppm(result_t *result, pixel_t *px)
{
    write_src(result, &(px->red[0].occurence), 0);
    write_src(result, &(px->red[0].value), 0);
    write_src(result, &(px->green[0].occurence), 0);
    write_src(result, &(px->green[0].value), 0);
    write_src(result, &(px->blue[0].occurence), 0);
    write_src(result, &(px->blue[0].value), 0);
    for (int i = 1, r = 0, g = 0, b = 0; i < px->nb_pixel; i++) {
        print_occ_pixel(result, px->red, &r);
        print_occ_pixel(result, px->green, &g);
        print_occ_pixel(result, px->blue, &b);
    }
}
