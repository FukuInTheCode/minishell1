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

int my_shell(void)
{
    char buf[1001] = {0};
    char cmd_buf[1001] = {0};
    int error = 0;
    char *argv[1001] = {0};

    for (int len = 0;true;) {
        write(1, "$> ", 3);
        len = read(0, buf, 1000) - 1;
        if (!my_strncmp(buf, "exit", 4) || len < 0)
            break;
        buf[len] = 0;
        cmd_argv(buf, argv);
        error = cmd_run(cmd_buf, argv);
        my_memset(buf, 0, len), my_memset(cmd_buf, 0, my_strlen(cmd_buf));
        reset_argv(argv);
    }
    return error;
}
