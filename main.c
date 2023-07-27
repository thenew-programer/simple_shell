#include "main.h"

/**
<<<<<<< Updated upstream
* main - function that execute the commands.
* @argc: argument count
* @argv: array containing the command and the options
* Return: 0 on success.
*/



int main(int __attribute((unused)) argc, char **argv)
=======
 * main - Entry point of the shell program.
 * @ac: Argument count.
 * @av: Array of strings containing the arguments.
 * @env: Array of strings containing the environment variables.
 * Return: The exit status value.
 **/
int main(int ac, char *av[], char **env)
>>>>>>> Stashed changes
{
    int count_exe = 1;
    int status_exit = 0;

<<<<<<< Updated upstream

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "-> ", 3);
		input = get_input();
		if (!input)
			continue;
		tokens = tokenize(input);
		if (builtin(tokens, input) == 0)
		{
			_free(2, input, tokens);
			continue;
		}
		cmd = path_handler(tokens[0]);
		if (cmd == NULL)
		{
			_write_err(argv[0], "command not found: ", tokens[0]);
			_free(2, input, tokens);
			continue;
		}
		if (execute(tokens, cmd) == -100)
		{
			_write_err(argv[0], "An error occurred while executing -> ", tokens[0]);
		}
		_free(3, input, tokens, cmd);
	}
	return (0);
=======
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
>>>>>>> Stashed changes
}



