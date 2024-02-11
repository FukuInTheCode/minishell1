/*
** EPITECH PROJECT, 2024
** cmd_run.c
** File description:
** cmd_run.c
*/

#include "my.h"

int cmd_exec(char *cmd_buf, char *argv[])
{
    if (cmd_exist(*argv, cmd_buf))
        return run_cmd(cmd_buf, argv);
    return 127;
}
