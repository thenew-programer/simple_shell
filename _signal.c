#include "main.h"
/**
 * This function is a signal handler for the SIGINT signal.
 * It writes a prompt to the standard output when the signal is received.
 * 
 * @param signal The signal number
 * @return Void
 */
void signal_handler(int signal)
{
    if (signal)
        write(STDIN_FILENO, "\n#cisfun$ ", 10);
}