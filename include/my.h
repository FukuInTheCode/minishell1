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
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
char *my_strdup(char const *);
int my_getnbr(char const *);
bool my_strstr(char const *, char const *);

int cmd_exec(char *, char *[], char ***);
char *my_getenv(char const *, char **);
bool cmd_exist(char const *, char[], char **);
bool cmd_is_script(char const *);
char **cmd_argv(char *, char *[]);
bool do_exit(char *[], int *);
char **my_env_cp(char **, uint8_t);
int my_env_free(char **);

int my_cd(char *[], char ***);
int my_env(char *[], char **);
int my_unsetenv(char const *, char ***);
int my_setenv(char const *, char *, char ***);

int my_shell(char ***);

#endif
