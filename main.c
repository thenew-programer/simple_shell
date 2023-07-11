#include "main.h"

/**
* main - function that execute the commands.
* @argc: argument count
* @argv: array containing the command and the options
* @env: array containing all the environment vars.
* Return: 0 on success.
*/

int main(int argc, char **argv, char **env)
{
	char *input, **tokens, *cmd, *init_cmd;

	while (1) {
		if (isatty(STDIN_FILENO) == 1)
			printf("-> ");
		input = get_input();
		if (!input) continue;
		/* Temp code*/
		if (strcmp(input, "exit") == 0) {
			free(input);
			exit(0);
		}
		/* end Temp code*/
		tokens = tokenize(input);
		cmd = path_handler(tokens[0]);
		execute(tokens, cmd);
		free(tokens);
		free(input);
		free(cmd);
	}
	return (0);
}
