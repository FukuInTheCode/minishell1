/*
** EPITECH PROJECT, 2024
** env_free.c
** File description:
** env_free.c
*/

#include "my.h"

int my_env_free(char **envp)
{
    for (int i = 0; envp[i]; i++)
        free(envp[i]);
    free(envp);
    return 0;
}
