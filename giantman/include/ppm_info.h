/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-antman-adrien.audiard
** File description:
** ppm_info.h
*/

#ifndef B_CPE_110_LYN_1_1_ANTMAN_ADRIEN_AUDIARD_PPM_INFO_H
    #define B_CPE_110_LYN_1_1_ANTMAN_ADRIEN_AUDIARD_PPM_INFO_H

    #include "prototype.h"

    typedef struct {
        int value;
        int occ;
        char str[5];
        int len;
    } rgb_t;

    typedef struct {
        rgb_t red;
        rgb_t green;
        rgb_t blue;
    } pixel_t;

    typedef struct {
        int len;
        char *buf;
    } buffer_t;

#endif
