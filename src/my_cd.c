/*
** EPITECH PROJECT, 2024
** my_cd.c
** File description:
** my_cd.c
*/

#include "my.h"

int my_cd(char *argv[])
{
    struct stat s;

    if (!argv[1] || argv[2])
        return 1;
    lstat(argv[1], &s);
    if (!S_ISDIR(s.st_mode))
        return 1;
    chdir(argv[1]);
    return 0;
}
