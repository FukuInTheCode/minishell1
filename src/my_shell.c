/*
** EPITECH PROJECT, 2024
** my_shell.c
** File description:
** my_shell.c
*/

#include "my.h"

static char **reset_argv(char *argv[])
{
    for (int i = 0; argv[i]; i++) {
        free(argv[i]);
        argv[i] = NULL;
    }
    return argv;
}

static int get_input(char **buf, size_t n, int len)
{
    write(1, "$> ", 3);
    len = getline(buf, &n, stdin);
    if (len < 0)
        return 1;
    (*buf)[len - 1] = 0;
    return 0;
}

int my_shell(char ***envp)
{
    char *buf = NULL;
    char cmd_buf[1001] = {0};
    int error = 0;
    char *argv[1001] = {0};

    for (; true;) {
        if (get_input(&buf, 0, 0))
            break;
        if (!*buf)
            continue;
        cmd_argv(buf, argv);
        if (do_exit(argv, &error))
            break;
        error = cmd_exec(cmd_buf, argv, envp);
        my_memset(cmd_buf, 0, my_strlen(cmd_buf));
        reset_argv(argv);
    }
    free(buf);
    return error;
}
