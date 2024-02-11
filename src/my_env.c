/*
** EPITECH PROJECT, 2024
** my_env.c
** File description:
** my_env.c
*/

#include "my.h"

extern char **environ;

int my_env(char *argv[])
{
    if (argv[1])
        return 1;
    for (int i = 0; environ[i]; i++)
        write(1, environ[i], my_strlen(environ[i])), write(1, "\n", 1);
    return 0;
}