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
        write(1, "\n", 1);
        write(1, buf, len);
        my_memset(buf, 0, len);
    }
    return 0;
}
