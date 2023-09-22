#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @data: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(data_t *data)
{
	return (isatty(STDIN_FILENO) && data->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @x: the char to check
 * @delimeter: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char x, char *delimeter)
{
	while (*delimeter)
		if (*delimeter++ == x)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @x: The character to input
 * Return: 1 if x is alphabetic, 0 otherwise
 */

int _isalpha(int x)
{
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @y: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *y)
{
	int m, n = 1, o = 0, p;
	unsigned int q = 0;

	for (m = 0; y[m] != '\0' && o != 2; m++)
	{
		if (y[m] == '-')
			n *= -1;

		if (y[m] >= '0' && y[m] <= '9')
		{
			o = 1;
			q *= 10;
			q += (y[m] - '0');
		}
		else if (o == 1)
			o = 2;
	}

	if (n == -1)
		p = -q;
	else
		p = q;

	return (p);
}
