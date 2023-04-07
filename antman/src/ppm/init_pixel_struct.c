/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** init_pixel_struct.c
*/

#include "../../include/prototype.h"

int get_nb_pixel(buffer_t *buffer, int index)
{
    int nb = 0;
    for (index; index < buffer->len; index++) {
        if (buffer->buf[index] == '\n')
            nb++;
    }
    return nb / 3;
}

pixel_t *init_pixel(buffer_t *buffer, int *index)
{
    pixel_t *px = malloc(sizeof(pixel_t));
    if (px == NULL)
        return NULL;
    px->nb_pixel = get_nb_pixel(buffer, *index);
    if (px->nb_pixel == 0)
        return NULL;
    px->red = malloc(sizeof(rgb_t) * px->nb_pixel);
    px->green = malloc(sizeof(rgb_t) * px->nb_pixel);
    px->blue = malloc(sizeof(rgb_t) * px->nb_pixel);
    if (px->red == NULL || px->green == NULL || px->blue == NULL)
        return NULL;
    px->red[0].value = my_getnbr_ppm(buffer->buf, index);
    px->red[0].occurence = 0;
    px->green[0].value = my_getnbr_ppm(buffer->buf, index);
    px->green[0].occurence = 0;
    px->blue[0].value = my_getnbr_ppm(buffer->buf, index);
    px->blue[0].occurence = 0;
    return px;
}
