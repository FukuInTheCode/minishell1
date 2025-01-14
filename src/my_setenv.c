/*
** EPITECH PROJECT, 2024
** my_setenv.c
** File description:
** my_setenv.c
*/

#include "my.h"

static size_t get_env_size(char **environ)
{
    int len = 0;

    for (int i = 0; environ[i]; i++)
        len++;
    return len;
}

static int add_env(char const *var, char const *value, char ***environ)
{
    size_t env_len = get_env_size(*environ) + 2;
    char **new_env = malloc(sizeof(char *) * env_len);
    int i = 0;

    if (!new_env)
        return 84;
    for (; (*environ)[i]; i++)
        new_env[i] = (*environ)[i];
    new_env[i] = malloc(my_strlen(var) + my_strlen(value) + 2);
    if (!new_env[i])
        return 84;
    my_memset(new_env[i], 0, my_strlen(var) + my_strlen(value) + 2);
    my_strcat(new_env[i], var);
    my_strcat(new_env[i], "=");
    my_strcat(new_env[i], value);
    new_env[i + 1] = NULL;
    *environ = new_env;
    return 0;
}

static bool check_name(char const *var)
{
    if (!('a' <= *var && *var <= 'z') && !('A' <= *var && *var <= 'Z'))
        return write(2, "setenv: Variable name "
                "must begin with a letter.\n", 48), false;
    for (int i = 0; var[i]; i++)
        if (!('0' <= var[i] && var[i] <= '9')
            && !('a' <= var[i] && var[i] <= 'z') &&
            !('A' <= var[i] && var[i] <= 'Z')
            && var[i] != '_')
            return write(2, "setenv: Variable name must "
                     "contain alphanumeric characters.\n", 60), false;
    return true;
}

static int change_env(char const *var, char const *value, char ***environ)
{
    size_t env_size = get_env_size(*environ) + 1;
    char **new_env = malloc(sizeof(char *) * env_size);

    if (!new_env)
        return 84;
    for (int i = 0; i < env_size - 1; i++) {
        new_env[i] = (*environ)[i];
        if (my_strncmp((*environ)[i], var, my_strlen(var)) ||
            (*environ)[i][my_strlen(var)] != '=')
            continue;
        new_env[i] = malloc(my_strlen(var) + my_strlen(value) + 2);
        if (!new_env[i])
            return 84;
        my_memset(new_env[i], 0, my_strlen(var) + my_strlen(value) + 2);
        my_strcat(new_env[i], var);
        my_strcat(new_env[i], "="), my_strcat(new_env[i], value);
    }
    new_env[env_size - 1] = NULL;
    *environ = new_env;
    return 0;
}

int my_setenv(char const *var, char *value, char ***environ)
{
    bool is_inside = false;

    if (!var)
        return 84;
    if (!check_name(var))
        return 1;
    if (!value)
        value = "";
    for (int i = 0; (*environ)[i]; i++)
        if (!my_strncmp((*environ)[i], var, my_strlen(var)) &&
            (*environ)[i][my_strlen(var)] == '=')
            is_inside = true;
    if (is_inside)
        return change_env(var, value, environ);
    return add_env(var, value, environ);
}
