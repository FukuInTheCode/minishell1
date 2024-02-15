/*
** EPITECH PROJECT, 2024
** env_cp.c
** File description:
** env_cp.c
*/

#include "my.h"

static size_t get_env_size(char **envp)
{
    size_t size = 0;

    for (; envp[size]; size++);
    return size;
}

char **my_env_cp(char **envp, uint8_t malloc_more)
{
    size_t size = get_env_size(envp) + 1 + malloc_more;
    char **new_envp = malloc(sizeof(char *) * size);

    for (size_t i = 0; i < size + 1; i++)
        new_envp[i] = NULL;
    for (int i = 0; envp[i]; i++)
        new_envp[i] = new_envp[i];
    return env;
}
