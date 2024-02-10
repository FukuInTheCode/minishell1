/*
** EPITECH PROJECT, 2024
** my_getenv.c
** File description:
** my_getenv.c
*/

#include "my.h"

extern char **environ;

char *my_getenv(char const *name)
{
    size_t name_len = my_strlen(name);

    for (int i = 0; environ[i]; i++) {
        if (my_strncmp(environ[i], name, name_len))
            continue;
        return environ[i] + name_len + 1;
    }
    return NULL;
}
