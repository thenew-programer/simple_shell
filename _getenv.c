#include "main.h"
/**
 * This function retrieves the value of an environment variable.
 * 
 * @param name The name of the environment variable
 * @param env The global environment system variable
 * @return The value of the environment variable as a string
 **/
char *getEnvironmentVariable(char *name, char **env)
{
    char *token1 = NULL, *token2 = NULL;
    char *envName = NULL, *currentEnv = NULL;
    int i = 0;

    envName = duplicateString(name);

    while (env[i] && env)
    {
        currentEnv = NULL;
        token2 = NULL;
        currentEnv = duplicateString(env[i]);
        token1 = strtok(currentEnv, "=");
        token2 = duplicateString(strtok(NULL, "="));
        if (compareStrings(envName, token1) == 0)
        {
            break;
        }
        free(currentEnv);
        free(token2);
        i++;
    }
    free(currentEnv);
    currentEnv = NULL;
    free(envName);
    return token2;
}