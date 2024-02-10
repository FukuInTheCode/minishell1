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
    char cmd_buf[1001] = {0};

    for (int len = 0;true;) {
        write(1, "$> ", 3);
        len = read(0, buf, 1000) - 1;
        buf[len] = 0;
        if (cmd_exist(buf, cmd_buf))
            write(1, cmd_buf, my_strlen(cmd_buf)) && write(1, "\n", 1);
        my_memset(buf, 0, len);
        my_memset(cmd_buf, 0, my_strlen(cmd_buf));
    }
    return 0;
}
