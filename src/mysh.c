/*
** EPITECH PROJECT, 2024
** mysh.c
** File description:
** mysh.c
*/

#include "my.h"

int main(int argc, char **argv, char **envp)
{
    int return_value = 0;

    envp = my_env_cp(envp, 0);
    return_value = my_shell(&envp);
    my_env_free(envp);
    return return_value;
}
