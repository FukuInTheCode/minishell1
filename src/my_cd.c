/*
** EPITECH PROJECT, 2024
** my_cd.c
** File description:
** my_cd.c
*/

#include "my.h"

static int print_error(char const *path, char const *msg)
{
    write(2, path, my_strlen(path));
    write(2, msg, my_strlen(msg));
    return 1;
}

int my_cd(char *argv[], char ***envp)
{
    struct stat s;
    char *path = NULL;
    char buf[1001] = {0};

    path = argv[1];
    if (!argv[1] || !my_strcmp("~", argv[1]))
        path = my_getenv("HOME", *envp);
    if (argv[1] && !my_strcmp("-", argv[1]))
        path = my_getenv("OLDPWD", *envp);
    if (!path || access(path, F_OK))
        return print_error(path, ": No such file or directory.\n");
    lstat(path, &s);
    if (!S_ISDIR(s.st_mode))
        return print_error(path, ": Not a directory.\n");
    my_setenv("OLDPWD", my_getenv("PWD", *envp), envp);
    chdir(path);
    getcwd(buf, 1000);
    my_setenv("PWD", buf, envp);
    return 0;
}
