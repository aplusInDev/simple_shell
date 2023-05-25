#include "main.h"

/**
 * _memcpy - copies memory area.
 *
 * @dest: destination memory area
 * @src: source memory area
 * @n: bytes of the memory
 *
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * _strcmp - compares two strings
 *
 *@s1: first string
 *@s2: second string
 *
 *Return: integer
 */
int _strcmp(const char *s1, char *s2)
{
	for (; *s1 == *s2; s1++, s2++)
	{
		if (*s1 == '\0')
			return (0);
	}
	return (*s1 - *s2);
}
/**
 * _strncmp - compares n characters
 * @s1: first string
 * @s2: second string
 * @n: number
 * Return: integer
 */
int _strncmp(const char *s1, char *s2, int n)
{
	for (; n && *s1 == *s2; n--, s1++, s2++)
		;
	if (n)
		return (*s1 - *s2);
	return (0);
}
/**
 * _strlen - string length
 *
 *@s: string
 * Return: length if string
 */

size_t _strlen(char *s)
{
	if (!s || *s == '\0')
		return (0);
	return (1 + _strlen(s + 1));
}
