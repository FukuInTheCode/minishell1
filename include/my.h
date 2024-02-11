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
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <fcntl.h>

size_t my_strlen(char const *);
char *my_memset(char *, char, size_t buf_len);
char *my_strcat(char *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strcpy(char *, char const *);
char *my_strdup(char const *);


char *my_getenv(char const *);
bool cmd_exist(char const *, char[]);
char **cmd_argv(char *, char *[]);
int my_shell(void);

#endif
