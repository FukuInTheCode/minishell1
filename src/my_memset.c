/*
** EPITECH PROJECT, 2024
** my_memset.c
** File description:
** my_memset.c
*/

#include "my.h"

char *my_memset(char *buf, char c, size_t buf_len)
{
    for (int i = 0; i < buf_len, i++)
        buf[i] = c;
    return buf;
}
