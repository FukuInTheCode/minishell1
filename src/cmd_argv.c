/*
** EPITECH PROJECT, 2024
** cmd_argv.c
** File description:
** cmd_argv.c
*/

#include "my.h"

char **cmd_argv(char *buf, char *argv[])
{
    int i = 0;

    buf = my_strdup(buf);
    if (!buf)
        return NULL;
    for (char *tok = strtok(buf, " \t"); tok; tok = strtok(NULL, " \t")) {
        argv[i] = my_strdup(tok);
        i++;
    }
    return free(buf), argv;
}
