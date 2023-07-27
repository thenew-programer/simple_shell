#include "main.h"
/**
 * exitFunction - Function that returns a specific exit value
 * @line: Input buffer
 * @status: Current status value of the process
 * @av: Name of the program
 * @count: Counter
 *
 * Return: Exit value
 */
int exitFunction(char *line, int status, char *av, int count)
{
	char *arguments[3], *temp = NULL, *token = NULL, message[100];
	char lowercase_a = 'a', lowercase_z = 'z', uppercase_a = 'A', uppercase_z = 'Z';
	char character = '\0', *argument = NULL;
	int returnValue = 0, i = 0;

	temp = duplicateString(line);
	free(line);
	token = strtok(temp, " \t\n\r");
	for (i = 0; token != NULL; i++)
	{
		arguments[i] = token;
		token = strtok(NULL, " \t\n\r");
	}
	arguments[i] = NULL;
	if (arguments[1] == NULL)
	{
		free(temp);
		return status;
	}
	argument = duplicateString(arguments[1]);
	if (argument)
		character = *arguments[1];
	if ((character >= lowercase_a && character <= lowercase_z) ||
			(character >= uppercase_a && character <= uppercase_z) || (_atoi(argument)) < 0)
	{
		sprintf(message, "%s: %d: exit: Illegal number: %s\n", av, count, arguments[1]);
		write(2, message, _strlen(message));
		free(temp), free(argument);
		return 2;
	}
	if (argument)
	{
		returnValue = _atoi(arguments[1]);
		free(temp);
		free(argument);
		return returnValue;
	}
	free(argument);
	free(temp);
	return status;
}
/**
 * _atoi - Function that converts a string to an integer
 * @arr: String to convert to integer
 *
 * Return: Converted number value
 */
int _atoi(char *arr)
{
	int i = 0, converted = 0;

	for (i = 0; arr[i] != '\0'; ++i)
	{
		converted = converted * 10 + arr[i] - '0';
	}

	return converted;
}