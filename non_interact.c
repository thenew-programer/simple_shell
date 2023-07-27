#include "main.h"

/**
 * non_interact - This function handles non-interactive mode by showing an error message.
 * @av: Pointer to an array of strings containing all input arguments in each position.
 * Return: The exit status value (127).
 **/
int non_interact(char **av)
{
    char error_msg[100];

    // Format the error message with the program name (av[0]) and the file name (av[1]).
    sprintf(error_msg, "%s: 0: Cannot open file: %s\n", av[0], av[1]);

    // Write the error message to the standard error (file descriptor 2).
    write(2, error_msg, strlen(error_msg));

    // Return the exit status value 127 to indicate an error.
    return 127;
}
