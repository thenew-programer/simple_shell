#include "main.h"

/**
 * main - Entry point of the shell program.
 * @ac: Argument count.
 * @av: Array of strings containing the arguments.
 * @env: Array of strings containing the environment variables.
 * Return: The exit status value.
 **/
int main(int ac, char *av[], char **env)
{
    int count_exe = 1;
    int status_exit = 0;

    // Ignore unused argument warning for ac
    (void)ac;

    // Register signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, signal_handler);

    // If there are additional arguments, run non-interactive mode
    if (ac > 1)
    {
        status_exit = non_interact(av);
        return status_exit;
    }

    // Otherwise, run interactive mode
    status_exit = interactive(av, count_exe, env);
    return status_exit;
}



