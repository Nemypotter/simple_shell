#include "shell.h"

/**
 * _strdup - Duplicates string.
 * @src: Source string to duplicate.
 *
 * Return: Pointer(str).
 */
char *_strdup(const char *src)
{
	char *str;
	char *p;
	int len = 0;

	while (src[len])
		len++;

	str = malloc(len + 1);
	if (!str)
		return (NULL);

	p = str;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (str);
}


/**
 * _strlen - Calculates length of a string
 * @str: The string.
 *
 * Return: Length of the string.
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}


/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Difference between ASCII values of the first unmatched
 * characters, 0 if strings are identical.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}

	return (s1[i] - s2[i]);
}


/**
 * _atoi - Convert a string to an integer.
 *
 * @s: The string.
 *
 * Return: Integer.
 */
int _atoi(char *s)
{
	int sign = 1, i = 0;
	unsigned int res = 0;

	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	res *= sign;
	return (res);
}
