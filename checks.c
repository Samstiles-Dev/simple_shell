#include "shell.h"

/**
 * active - Checks whether the shell is running in interactive mode
 * @info: A pointer to a struct containing shell information
 * Return: 1 if the shell is in interactive mode, 0 otherwise
 */
int active(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * _delimeter - Checks if a character is a delimiter
 * @c: The character to be checked
 * @delim: The delimiter string to compare against
 * Return: 1 if the character is a delimiter, 0 if not
 */
int _delimeter(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
		{
			return (1);
		}
	return (0);
}

/**
 * _alpha_char - Checks if a character is alphabetic
 * @c: The character to be tested
 * Return: 1 if 'c' is an alphabetic character, 0 otherwise
 */
int _alpha_char(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Converts a string to an integer
 * @s: The input string to be converted
 * Return: The converted integer, or 0 if no numbers are found in the string
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
