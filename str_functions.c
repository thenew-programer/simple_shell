#include "main.h"

/**
 * _strcpy - Copies the string pointed to by src to the buffer pointed to by dest.
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 * Return: Pointer to the destination buffer.
 */
char *_strcpy(char *dest, char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

/**
 * _strlen - Returns the length of a string.
 * @s: Pointer to the input string.
 * Return: Length of the string.
 */
int _strlen(const char *s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        i++;
    }

    return i;
}

/**
 * _strcat - Concatenates two strings.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * Return: Pointer to the concatenated string.
 */
char *_strcat(char *dest, char *src)
{
    char *output = NULL;
    unsigned int i = 0, j = 0, len1 = 0, len2 = 0;

    len1 = _strlen(dest);
    len2 = _strlen(src);

    output = _calloc(len1 + len2 + 1, sizeof(char));
    if (output == NULL)
    {
        return NULL;
    }

    for (i = 0; i < len1; i++)
    {
        output[i] = dest[i];
    }

    for (j = 0; j < len2; j++, i++)
    {
        output[i] = src[j];
    }

    output[i] = '\0';

    return output;
}

/**
 * duplicateString - Copies a string.
 * @str: The string to be copied.
 * Return: A pointer to the copied string (a new allocated string).
 **/
char *duplicateString(char *str)
{
    int j, l;
    char *s;

    if (!str)
    {
        return NULL;
    }

    l = _strlen(str) + 1;

    s = _calloc(l, sizeof(char));
    if (!s)
    {
        return NULL;
    }

    for (j = 0; j < l; j++)
    {
        s[j] = str[j];
    }
    return s;
}
