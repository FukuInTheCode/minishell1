/*
** EPITECH PROJECT, 2024
** my_unsetenv.c
** File description:
** my_unsetenv.c
*/

#include "my.h"

extern char **environ;

static size_t get_env_size(void)
{
    size_t len = 0;

    for (int i = 0; environ[i]; i++)
        len++;
    return len;
}

int my_unsetenv(char const *name)
{
    size_t env_size = get_env_size() + 1;
    char **new_env = malloc(sizeof(char *) * env_size);
    int j = 0;

    if (!new_env || !name)
        return 84;
    for (int i = 0; i < env_size; i++) {
        if (!my_strncmp(environ[i], name, my_strlen(name)))
            new_env[i] = environ[j];
        j++;
    }
    return 0;
}
