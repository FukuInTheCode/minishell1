/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** my_strcat.c
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    for (; *dest; dest++);
    for (; *src; src++) {
        *dest = *src;
        dest++;
    }
    *dest = 0;
    return dest;
}
