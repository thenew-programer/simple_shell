#include "main.h"
#include <errno.h>
#include <signal.h>

/**
* main - function that execute the commands.
* @argc: argument count
* @argv: array containing the command and the options
* Return: 0 on success.
*/

volatile sig_atomic_t g_flag = 0;

void int_handler();

int main(int __attribute((unused)) argc, char **argv)
{
	char *input, **tokens ;/*, *cmd;*/
	errno = 0;
	signal(SIGINT, int_handler);


	while (1)
	{
		if (g_flag == 1)
			exit(0);
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "-> ", 3);
		input = get_input();
		if (!input)
			continue;
		tokens = (char **)malloc(sizeof(char *));
		tokens[0] = input;
		/*
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
		*/
		/*
		execute(tokens, cmd);
		_free(3, input, tokens, cmd);
		*/
		if (execute(tokens, input) == -100) {
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": No such file or directory\n", 28);
		}
		free(input);
		free(tokens);
	}
	printf("hello world\n");
	return (0);
}

void int_handler()
{
	g_flag = 1;
}
