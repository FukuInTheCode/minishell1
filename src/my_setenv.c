/*
** EPITECH PROJECT, 2024
** my_setenv.c
** File description:
** my_setenv.c
*/

#include "my.h"

extern char **environ;

static size_t get_env_size(void)
{
    int len = 0;

    for (int i = 0; environ[i]; i++)
        len++;
    return len;
}

static int add_env(char const *var, char const *value)
{
    size_t env_len = get_env_size() + 2;
    char **new_env = malloc(sizeof(char *) * env_len);
    int i = 0;

    if (!new_env)
        return 84;
    for (; environ[i]; i++)
        new_env[i] = environ[i];
    new_env[i] = malloc(my_strlen(var) + my_strlen(value) + 2);
    if (!new_env[i])
        return 84;
    my_memset(new_env[i], 0, my_strlen(var) + my_strlen(value) + 2);
    my_strcat(new_env[i], var);
    my_strcat(new_env[i], "=");
    my_strcat(new_env[i], value);
    new_env[i + 1] = NULL;
    environ = new_env;
    return 0;
}

static int change_env(char const *var, char const *value)
{
    size_t env_size = get_env_size() + 1;
    char **new_env = malloc(sizeof(char *) * env_size);

    if (!new_env)
        return 84;
    for (int i = 0; i < env_size - 1; i++) {
        new_env[i] = NULL;
        new_env[i] = environ[i];
        if (my_strncmp(environ[i], var, my_strlen(var)) ||
            environ[i][my_strlen(var)] != '=')
            continue;
        new_env[i] = malloc(my_strlen(var) + my_strlen(value) + 2);
        if (!new_env[i])
            return 84;
        my_memset(new_env[i], 0, my_strlen(var) + my_strlen(value) + 2);
        my_strcat(new_env[i], var);
        my_strcat(new_env[i], "=");
        my_strcat(new_env[i], value);
    }
    new_env[env_size - 1] = NULL;
    environ = new_env;
    return 0;
}

int my_setenv(char const *var, char const *value)
{
    bool is_inside = false;

    if (!var || !value)
        return 84;
    for (int i = 0; environ[i]; i++)
        if (!my_strncmp(environ[i], var, my_strlen(var)) &&
            environ[i][my_strlen(var)] == '=')
            is_inside = true;
    if (is_inside)
        return change_env(var, value);
    return add_env(var, value);
}
