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
    char *path = NULL;

    path = argv[1];
    if (!argv[1] || !my_strcmp("~", argv[1]))
        path = my_getenv("HOME");
    if (argv[1] && !my_strcmp("-", argv[1]))
        path = my_getenv("OLDPWD");
    if (!path || access(path, F_OK))
        return 1;
    lstat(path, &s);
    if (!S_ISDIR(s.st_mode))
        return 1;
    chdir(path);
    return 0;
}
