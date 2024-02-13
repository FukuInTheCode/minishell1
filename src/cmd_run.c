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
    status = status >> 8 * (status > 255);
    if (status == 139)
        write(2, "Segmentation fault (core dumped)\n", 34);
    return status;
}

int cmd_exec(char *cmd_buf, char *argv[])
{
    if (!my_strcmp(*argv, "cd"))
        return my_cd(argv);
    if (!my_strcmp(*argv, "env"))
        return my_env(argv);
    if (!my_strcmp(*argv, "unsetenv"))
        return my_unsetenv(argv[1]);
    if (!my_strcmp(*argv, "setenv") && argv[1])
        return my_setenv(argv[1], argv[2]);
    if (cmd_exist(*argv, cmd_buf))
        return run_cmd(cmd_buf, argv);
    if (cmd_is_script(*argv))
        return run_cmd(*argv, argv);
    write(2, "\n", 1);
    write(2, *argv, my_strlen(*argv));
    write(2, ": Command not found.\n", 21);
    return 1;
}
