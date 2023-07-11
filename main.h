#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

#define MAX_BUFFER 2048

char *get_input();
char **tokenize(char *);
int execute(char **argv, char *full_cmd);
char *path_handler(char *arg);
char *get_path();

/* Utility functions*/
int _strlen(char *str);
int _strlen_input(char *str);
int get_tokens_count(char *input, char *delimiter);
char *_strcat(char *, char *);
void _write_err(char *cmd, char *err);
#endif // MAIN_H
