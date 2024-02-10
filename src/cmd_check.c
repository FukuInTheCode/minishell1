/*
** EPITECH PROJECT, 2024
** cmd_check.c
** File description:
** cmd_check.c
*/

#include "my.h"

bool cmd_exist(char const *cmd)
{
    char *path_value = my_getenv("PATH");
    char current_dir[1001] = {0};
    int is_ok = 0;

    if (!path_value)
        return false;
    getcwd(current_dir, 1000);
    path_value = my_strdup(path_value);
    for (char *tok = strtok(path_value, ":"); tok; tok = strtok(NULL, ":")) {
        chdir(tok);
        is_ok = access(cmd, F_OK);
        chdir(current_dir);
        if (is_ok)
            continue;
        free(path_value);
        return true;
    }
    free(path_value);
    return false;
}
