/*
** EPITECH PROJECT, 2024
** my_exit.c
** File description:
** my_exit.c
*/

#include "my.h"

bool do_exit(char *argv[], int *ret)
{
    int i = 0;

    if (my_strcmp("exit", *argv))
        return false;
    if (!argv[1]) {
        *ret = 0;
        return true;
    }
    if (argv[2]) {
        *ret = 1;
        return false;
    }
    for (; argv[1][i] && ('0' <= argv[1][i] && argv[1][i] <= '9'); i++);
    if (argv[1][i])
        return false;
    *ret = my_getnbr(argv[1]);
    return true;
}
