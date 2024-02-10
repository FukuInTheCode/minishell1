/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <time.h>
    #include <limits.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <math.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <stdbool.h>
    #include <string.h>

size_t my_strlen(char const *);
char *my_memset(char *, char, size_t buf_len);
char *my_strcat(char *, char const *);
int my_strncmp(char const *, char const *, int);

char *my_getenv(char const *);
int my_shell(void);

#endif
