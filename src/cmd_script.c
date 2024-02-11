/*
** EPITECH PROJECT, 2024
** cmd_script.c
** File description:
** cmd_script.c
*/

#include "my.h"

bool cmd_is_script(char const *cmd)
{
    return access(cmd, X_OK) == 0;
}
