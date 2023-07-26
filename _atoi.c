#include "shell.h"

/**
 * interactive - returns shell in the event it is true in interactive mode
 * @info: struct the address
 *
 * Return: 1 if it is in interactive mode, 0 else
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks that the character is a delimeter
 * @c: the char that does the check
 * @delim: the delimeter that is a string
 * Return: 1 if it is true, 0 if it is false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int r)
{
	if ((r >= 'a' && r <= 'z') || (r >= 'A' && r <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int p, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (p = 0;  s[p] != '\0' && flag != 2; p++)
	{
		if (s[p] == '-')
			sign *= -1;

		if (s[p] >= '0' && s[p] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[p] - '0');
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
