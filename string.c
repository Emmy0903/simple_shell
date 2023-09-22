#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @a: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *a)
{
	int b = 0;

	if (!a)
		return (0);

	while (*a++)
		b++;
	return (b);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @a1: the first strang
 * @a2: the second strang
 *
 * Return: negative if a1 < a2, positive if a1 > a2, zero if a1 == a2
 */
int _strcmp(char *a1, char *a2)
{
	while (*a1 && *a2)
	{
		if (*a1 != *a2)
			return (*a1 - *a2);
		a1++;
		a2++;
	}
	if (*a1 == *a2)
		return (0);
	else
		return (*a1 < *a2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @pam: string to search
 * @dem: the substring to find
 *
 * Return: address of next char of pam or NULL
 */
char *starts_with(const char *pam, const char *dem)
{
	while (*dem)
		if (*dem++ != *pam++)
			return (NULL);
	return ((char *)pam);
}

/**
 * _strcat - concatenates two strings
 * @m: the destination buffer
 * @n: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *m, char *n)
{
	char *ret = m;

	while (*m)
		m++;
	while (*n)
		*m++ = *n++;
	*m = *n;
	return (ret);
}
