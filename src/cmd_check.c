/*
** EPITECH PROJECT, 2024
** cmd_check.c
** File description:
** cmd_check.c
*/

#include "my.h"

static int get_access(char const *cmd, char const *tok, char const *cdir)
{
    int ret = 0;

    chdir(tok);
    ret = access(cmd, F_OK);
    chdir(cdir);
    return ret;
}

static char *get_cmd_path(char buf[], char const *cmd, char const *tok)
{
    my_strcat(buf, tok);
    if (buf[my_strlen(buf) - 1] != '/')
        my_strcat(buf, "/");
    my_strcat(buf, cmd);
    return buf;
}



bool cmd_exist(char const *cmd, char buf[])
{
    char *path_value = my_getenv("PATH");
    char current_dir[1001] = {0};
    int is_ok = 0;

    if (!path_value)
        return false;
    getcwd(current_dir, 1000);
    if (*cmd == '/' && !get_access(cmd + 1, "/", current_dir))
        return get_cmd_path(buf, cmd + 1, "/"), true;
    path_value = my_strdup(path_value);
    for (char *tok = strtok(path_value, ":"); tok; tok = strtok(NULL, ":")) {
        is_ok = get_access(cmd, tok, current_dir);
        if (is_ok)
            continue;
        get_cmd_path(buf, cmd, tok);
        return free(path_value), true;
    }
    return free(path_value), false;
}
