/*
** EPITECH PROJECT, 2024
** my_shell.c
** File description:
** my_shell.c
*/

#include "my.h"

int my_shell(void)
{
    char buf[1001] = {0};

    for (int len = 0;true;) {
        write(1, "$> ", 3);
        len = read(0, buf, 1000);
        buf[len - 1] = 0;
        len--;
        if (cmd_exist(buf))
            write(1, "cmd exist\n", 10);
        my_memset(buf, 0, len);
    }
    return 0;
}
