/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** compress_ppm
*/

#include "../../include/prototype.h"

int my_getnbr_ppm(char *buf, int *i)
{
    int res = 0;
    for (; buf[*i] != '\n'; (*i)++) {
        res *= 10;
        res += buf[*i] - '0';
    }
    (*i)++;
    return res;
}

void get_occurence(rgb_t *rgb, char *buf, int *index, int *rgba)
{
    int nb = my_getnbr_ppm(buf, index);
    if (nb == rgb[*rgba].value && rgb[*rgba].occurence < 255)
        rgb[*rgba].occurence += 1;
    else {
        (*rgba)++;
        rgb[*rgba].value = nb;
        rgb[*rgba].occurence = 0;
    }
}

void pixel_struct(result_t *result, buffer_t *buffer, int index)
{
    int header = index;
    pixel_t *px = init_pixel(buffer, &index);
    result->res = malloc(sizeof(char) * buffer->len);
    if (px == NULL || result->res == NULL)
        return;
    for (int i = 1, r = 0, g = 0, b = 0, nb = 0; i < px->nb_pixel; i++) {
        get_occurence(px->red, buffer->buf, &index, &r);
        get_occurence(px->green, buffer->buf, &index, &g);
        get_occurence(px->blue, buffer->buf, &index, &b);
    }
    write(1, buffer->buf, header);
    print_ppm(result, px);
    write(1, result->res, result->len);
    free(px->red);
    free(px->green);
    free(px->blue);
    free(px);
    free(result->res);
}

int compress_ppm(int ac, char **av)
{
    buffer_t *buffer = NULL;
    result_t result = {.i = 0, .len = 0};
    int i = 0;
    int n = 0;
    if (init_buffer_struct(av, &buffer) == 84)
        return 84;
    if (buffer->len == 0)
        return 0;
    for (int j = 0, k = 0; k != 0 || j == 0; i++) {
        for (k = 0, j = 0; buffer->buf[i] != '\n'; i++) {
            j += buffer->buf[i] >= '0' && buffer->buf[i] <= '9' ? 1 : 0;
            k += buffer->buf[i] >= '0' && buffer->buf[i] <= '9' ? 0 : 1;
        }
        n++;
    }
    write(1, &n, 1);
    pixel_struct(&result, buffer, i);
    free(buffer->buf);
    free(buffer);
}
