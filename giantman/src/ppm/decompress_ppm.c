/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** decompress_ppm.c
*/

#include "../../include/prototype.h"

void ppm_nbr_to_str(rgb_t *rgb, int len)
{
    int mult = 1;
    rgb->len = len;
    for (int i = 2; i < len; i++) {
        mult *= 10;
    }
    for (int i = 0; i + 1 < len; i++, mult /= 10) {
        rgb->str[i] = rgb->value / mult + '0';
        rgb->value -= (rgb->str[i] - '0') * mult;
    }
    rgb->str[len - 1] = '\n';
    rgb->str[len] = '\0';
}

void get_occ_value(rgb_t *rgb, buffer_t *buffer, int *index)
{
    rgb->occ = buffer->buf[*index];
    rgb->occ = rgb->occ < 0 ? 256 + rgb->occ : rgb->occ;
    rgb->occ += 1;
    (*index)++;
    rgb->value = buffer->buf[*index];
    rgb->value = rgb->value < 0 ? 256 + rgb->value : rgb->value;
    (*index)++;
    if (0 <= rgb->value && rgb->value < 10)
        return ppm_nbr_to_str(rgb, 2);
    if (10 <= rgb->value && rgb->value < 100)
        return ppm_nbr_to_str(rgb, 3);
    return ppm_nbr_to_str(rgb, 4);
}

void print_rgb(result_t *result, rgb_t *rgb, buffer_t *buffer, int *index)
{
    if (rgb->occ == 0)
        get_occ_value(rgb, buffer, index);
    write_src(result, rgb->str, 0);
    rgb->occ -= 1;
}

void pixel_struct(result_t *result, buffer_t *buffer, int index)
{
    pixel_t px =
    {.red = {.occ = 0, .value = 0, .len = 0},
    .green = {.occ = 0, .value = 0, .len = 0},
    .blue = {.occ = 0, .value = 0, .len = 0}};
    for (; index < buffer->len;) {
        print_rgb(result, &(px.red), buffer, &index);
        print_rgb(result, &(px.green), buffer, &index);
        print_rgb(result, &(px.blue), buffer, &index);
    }
    while (px.red.occ != 0 || px.blue.occ != 0 || px.green.occ != 0) {
        print_rgb(result, &(px.red), buffer, &index);
        print_rgb(result, &(px.green), buffer, &index);
        print_rgb(result, &(px.blue), buffer, &index);
    }
}

int decompress_ppm(int ac, char **av)
{
    buffer_t *buffer = NULL;
    result_t result = {.i = 0, .len = 0};
    int nb;
    int i = 1;
    if (init_buffer_struct(av, &buffer) == 84)
        return 84;
    if (buffer->len == 0)
        return 0;
    nb = buffer->buf[0];
    for (; nb != 0; i++) {
        write(1, &(buffer->buf[i]), 1);
        if (buffer->buf[i] == '\n')
            nb--;
    }
    result.res = malloc(sizeof(char) * buffer->len * 100);
    pixel_struct(&result, buffer, i);
    write(1, result.res, result.len);
    free(result.res);
    free(buffer->buf);
    free(buffer);
}
