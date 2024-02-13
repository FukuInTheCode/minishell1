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

    return_value = my_shell();
    return WEXITSTATUS(return_value);
}
