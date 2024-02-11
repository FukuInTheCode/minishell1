/*
** EPITECH PROJECT, 2024
** cmd_run.c
** File description:
** cmd_run.c
*/

#include "my.h"

static int run_cmd(char const *cmd_buf, char *argv[])
{
    int status = 0;
    pid_t pid = fork();

    if (pid == 0)
        return execve(cmd_buf, argv, NULL);
    waitpid(pid, &status, 0);
    return status;
}

int cmd_exec(char *cmd_buf, char *argv[])
{
    if (cmd_exist(*argv, cmd_buf))
        return run_cmd(cmd_buf, argv);
    return 127;
}
