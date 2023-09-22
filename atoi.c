#include "shell.h"
#include <stddef.h>

/**
 * parse - splits a string into words
 * @str: the input string
 * @delimiters: the delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **parse(const char *str, const char *delimiters)
{
int i, j, k, m, numwords = 0;
char **tokens;

if (str == NULL || str[0] == '\0')
return (NULL);

if (!delimiters)
delimiters = " ";

for (i = 0; str[i] != '\0'; i++) {
if (!strchr(delimiters, str[i])) {
while (str[i] && !strchr(delimiters, str[i]))
                i++;
            numwords++;
        }
    }

if (numwords == 0)
return NULL;

tokens = malloc((numwords + 1) * sizeof(char *));
if (!tokens)
return NULL;

for (i = 0, j = 0; j < numwords; j++) {
while (str[i] && strchr(delimiters, str[i]))
            i++;

        k = 0;
while (str[i + k] && !strchr(delimiters, str[i + k]))
            k++;

        tokens[j] = malloc((k + 1) * sizeof(char));
        if (!tokens[j]) {
            for (k = 0; k < j; k++)
                free(tokens[k]);
            free(tokens);
            return NULL;
        }

        for (m = 0; m < k; m++)
            tokens[j][m] = str[i++];
        tokens[j][m] = '\0';
    }

    tokens[j] = NULL;
    return tokens;
}

/**
 * strtow2 - splits a string into words using a single delimiter character
 * @str: the input string
 * @delimiter: the delimiter character
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(const char *str, char delimiter)
{
    int i, j, k, m, numwords = 0;
    char **tokens;

    if (str == NULL || str[0] == '\0')
        return NULL;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != delimiter) {
            while (str[i] && str[i] != delimiter)
                i++;
            numwords++;
        }
    }

    if (numwords == 0)
        return NULL;

    tokens = malloc((numwords + 1) * sizeof(char *));
    if (!tokens)
        return NULL;

    for (i = 0, j = 0; j < numwords; j++) {
        while (str[i] == delimiter)
            i++;

        k = 0;
        while (str[i + k] != delimiter && str[i + k])
            k++;

        tokens[j] = malloc((k + 1) * sizeof(char));
        if (!tokens[j]) {
            for (k = 0; k < j; k++)
                free(tokens[k]);
            free(tokens);
            return NULL;
        }

        for (m = 0; m < k; m++)
            tokens[j][m] = str[i++];
        tokens[j][m] = '\0';
    }

    tokens[j] = NULL;
    return tokens;
}
