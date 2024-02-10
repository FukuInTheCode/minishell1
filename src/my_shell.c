/*
** EPITECH PROJECT, 2024
** my_shell.c
** File description:
** my_shell.c
*/

#include "my.h"

static int run_cmd(char const *cmd_buf, char const *buf)
{
    int status = 0;
    pid_t pid = fork();

    if (pid == 0)
        return execve(cmd_buf, (char const *[]){buf, NULL}, NULL);
    waitpid(pid, &status, 0);
    return status;
}

int my_shell(void)
{
    char buf[1001] = {0};
    char cmd_buf[1001] = {0};
    int error = 0;

    for (int len = 0;true;) {
        write(1, "$> ", 3);
        len = read(0, buf, 1000) - 1;
        buf[len] = 0;
        if (cmd_exist(buf, cmd_buf))
            error |= run_cmd(cmd_buf, buf);
        my_memset(buf, 0, len);
        my_memset(cmd_buf, 0, my_strlen(cmd_buf));
    }
    return error;
}
