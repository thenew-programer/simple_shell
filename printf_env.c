#include "main.h"

/**
 * print_env - Print the global environment variables.
 * @env: Array of strings containing the global environment variables.
 * Return: The exit status value (EXIT_SUCCESS).
 **/

int print_env(char **env)
{
    int i = 0;

    // Loop through the environment variables and print them one by one.
    while (env[i] != NULL)
    {
        write(STDOUT_FILENO, env[i], _strlen(env[i]));
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }

    // Return the exit status value EXIT_SUCCESS (0) to indicate successful execution.
    return EXIT_SUCCESS;
}
