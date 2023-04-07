/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** display the number given as a parameter
*/

#include "../../include/my_lib.h"

int rev(int nb)
{
    int factor = 1;
    int modulo = 0;
    int reverse = 0;
    while (nb > 0){
        modulo = nb % 10;
        nb = nb / 10;
        reverse *= 10;
        reverse += modulo;
    }
    return (reverse);
}

int len_nb(int nb)
{
    int count = 0;
    while (nb > 0){
        nb = nb / 10;
        count += 1;
    }
    return (count);
}

int my_put_nbr(int nb)
{
    if (nb == 0){
        my_putchar(48);
        return (0);
    } else {
        int reverse_nb = 0;
        if (nb < 0){
            nb = -nb;
            my_putchar('-');
        }
        reverse_nb = rev(nb);
        int len = len_nb(nb);

        for (int i = 0; i < len; i++){
            my_putchar((reverse_nb % 10) + 48);
            reverse_nb = reverse_nb / 10;
        }
    }
}
