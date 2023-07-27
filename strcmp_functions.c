#include "main.h"

/**
 * _strcmp - Compare two strings.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 * Description: This function compares two strings character by character.
 * Return: An integer indicating the difference between the strings.
 */
int _strcmp(char *s1, char *s2)
{
    int j;

    for (j = 0; s1[j] != '\0' || s2[j] != '\0'; j++)
    {
        if (s1[j] != s2[j])
        {
            return (s1[j] - s2[j]);
        }
    }

    return 0;
}

/**
 * _strncmp - Compare two strings up to a given number of characters.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 * @n: Number of characters to compare.
 * Return: An integer indicating the difference between the strings.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
    int i = 0, j = 0;

    while (n && s1[i] && (s1[i] == s2[j]))
    {
        i++;
        j++;
        n--;
    }

    if (n == 0)
    {
        return 0;
    }
    else
    {
        return (s1[i] - s2[j]);
    }
}
