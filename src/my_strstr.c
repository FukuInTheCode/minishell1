/*
** EPITECH PROJECT, 2024
** my_strstr.c
** File description:
** my_strstr.c
*/

#include "my.h"

bool my_strstr(char const *s1, char const *s2)
{
    size_t s2_len = my_strlen(s2);

    for (int i = 0; s1[i]; i++)
        if (!my_strncmp(s1 + i, s2, s2_len))
            return true;
    return false;
}
