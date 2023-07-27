#ifndef MAIN_H
#define MAIN_H

/* Standard C Library Headers */
#include <stdio.h>
#include <stdlib.h>
<<<<<<< Updated upstream
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
=======
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
>>>>>>> Stashed changes

/* Shell functions defined in shell_functions.c */
int non_interact(char **av);
int interactive(char *av[], int count_exe, char **env);
int create_process(char *av[], int count_exe, char **env);
char *getEnvironmentVariable(char *name, char **env);
int print_env(char **env);
void signal_handler(int sigint);
int exitFunction(char *line, int status, char *av, int count);
int _atoi(char *arr);

/* Path functions defined in path_functions.c */
char *validate_file(char *full_path, char *file);

<<<<<<< Updated upstream


/**
 * struct Builtin - struct that holds count of
 * built in command in shell;
 * @cmd: name of the command
 * @func: pointer to function
 */
typedef struct Builtin
{
	char *cmd;
	void (*func)(void);
} builtin_t;
=======
/* String functions defined in str_functions.c */
char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
char *_strcat(char *dest, char *src);
char *duplicateString(char *str);
>>>>>>> Stashed changes

/* String comparison functions defined in strcmp_functions.c */
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/* Memory allocation functions */
char *_memset(char *s, char b, unsigned int n);
void *_calloc(unsigned int nmemb, int size);
unsigned int length_array(char **p);

#endif /* MAIN_H */
