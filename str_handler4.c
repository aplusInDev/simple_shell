#include "main.h"

/**
 * _strstr - locates a substring.
 *
 * @haystack: string
 * @needle: string looking for
 *
 * Return: location or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (*haystack == '\0' && *needle == '\0')
		return (NULL);
	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (needle[j] != haystack[i + j])
				break;
		}
		if (needle[j] == '\0')
			return (&haystack[i]);
	}
	return (NULL);
}
/**
 * _strpbrk - searches a string for any of a set of bytes.
 *
 * @s: arg1
 * @accept: arg2
 *
 * Return: 0
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	if (*s == '\0' && *accept == '\0')
		return (0);
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				break;
		}
		if (accept[j] != '\0')
			break;
	}
	if (s[i] != '\0')
		return (&s[i]);
	return (0);
}
/**
 * _strcat - concatenates two strings
 *
 *@src: first string
 *@dest: second string
 *
 *Return: dest string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	dest[i] = ' ';
	for (j = 0; src[j] != '\0'; i++, j++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}
