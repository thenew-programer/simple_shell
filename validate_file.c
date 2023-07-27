#include "main.h"

/**
 * validate_file - Validate if the filename exists in the directories listed in PATH.
 * @full_path: The entire PATH environment variable.
 * @file: The name of the command to search for.
 * Return: The full path to the file if found, otherwise NULL.
 **/
char *validate_file(char *full_path, char *file)
{
    struct stat st;
    char *path_name;
    char *token = NULL;

    token = strtok(full_path, ":");
    while (token != NULL)
    {
        path_name = malloc((_strlen(token) + _strlen(file) + 2) * sizeof(char));
        if (path_name == NULL)
        {
            return file;
        }

        // Concatenate the token (directory) and file name to form the complete path.
        _strcpy(path_name, token);
        _strcat(path_name, "/");
        _strcat(path_name, file);

        // Check if the file exists in the directory.
        if (stat(path_name, &st) == 0)
        {
            return path_name;
        }

        free(path_name);
        token = strtok(NULL, ":");
    }

    return NULL; // File not found in any directory in PATH.
}
