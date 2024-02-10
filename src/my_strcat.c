/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** my_strcat.c
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    char *return_ptr = dest;

    for (; *dest; dest++);
    for (int i = 0; src[i]; i++) {
        *dest = src[i];
        dest++;
    }
    *dest = 0;
    return return_ptr;
}
