#include "main.h"

/**
 * interactive - This function reads command lines using getline in interactive
 * and non-interactive mode (echo / cat).
 * @av: Pointer to an array of strings with the name of the function executed
 *      in the first position.
 * @count_exe: Keeps track of how many commands have been executed.
 * @env: Environment variables.
 * Return: The exit status value.
 **/
int interactive(char *av[], int count_exe, char **env)
{
    int interactive = 1, status_process = 0, i = 0, read = 0, ext = 0;
    size_t len = 0;
    char *line = NULL, *args[32], *token = NULL;

    if (isatty(STDIN_FILENO) == 0)
        interactive = 0;

    while (1)
    {
        if (interactive == 1)
            write(STDIN_FILENO, "#cisfun$ ", 9);

        read = getline(&line, &len, stdin);

        if (read == EOF)
        {
            free(line);
            write(STDIN_FILENO, "\n", 1);
            return status_process;
        }
        else if (_strncmp(line, "exit\n", 4) == 0)
        {
            ext = exitFunction(line, status_process, av[0], count_exe);
            return ext;
        }
        else
        {
            if (_strncmp(line, "env\n", 3) == 0)
            {
                status_process = print_env(env);
                count_exe++;
            }
            else if (read > 1)
            {
                token = strtok(line, " \t\n\r");
                args[0] = av[0];

                for (i = 1; i < 32 && token != NULL; i++)
                {
                    args[i] = token;
                    token = strtok(NULL, " \t\n\r");
                }

                args[i] = NULL;

                if (args[1])
                    status_process = create_process(args, count_exe, env);
            }

            count_exe++;
        }
    }

    return status_process;
}
