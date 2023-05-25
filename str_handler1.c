#include "main.h"

/**
 * print_string - printf str
 * @str: gving str
 * @i: giving int
 * Return: printed char
 */
int print_string(int i, char *str)
{
	if (i == 1)
		return (write(STDOUT_FILENO, str, _strlen(str)));
	return (write(STDERR_FILENO, str, _strlen(str)));
}
/**
 * to_string - to string
 * @n: given number
 * @i: given int
 * Return: printed char
 */
int to_string(int i, unsigned int n)
{
	char d;

	if (n >= 10)
		return (to_string(i, n / 10) + to_string(i, n % 10));
	d = '0' + n;
	if (i == 1)
		return (write(STDOUT_FILENO, &d, 1));
	return (write(STDERR_FILENO, &d, 1));
}
/**
 * _atoi - convert a string to an integer
 *
 *@s: string
 * Return: char nbr
 */
int _atoi(char *s)
{
	int i, m;
	unsigned int n;

	for (i = 0, n = 0, m = 1; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			m = -m;
		if (s[i] >= '0' && s[i] <= '9')
		{
			n = (n * 10) + (s[i] - '0');
			if (!(s[i + 1] >= '0' && s[i + 1] <= '9'))
				break;
		}
	}
	n *= m;
	return (n);
}
/**
 * _strcpy - copies the string pointed to by src to dest
 *
 *@src: string
 *@dest: buffer
 * Return: string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
