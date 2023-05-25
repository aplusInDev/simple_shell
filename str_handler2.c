#include "main.h"

/**
 * replace_substring - check code
 * @str: input string
 * @old_substr: old substring
 * @new_substr: input substring
 * Return: command decomposition
 */
void replace_substring(char *str, char *old_substr, char *new_substr)
{
	char *ptr = NULL;
	size_t old_len = _strlen(old_substr);
	size_t new_len = _strlen(new_substr);
	size_t k = new_len, l = old_len;

	ptr = _strstr(str, old_substr);
	if (!ptr)
		return;
	do {
		ptr[k++] = ptr[l++];
	} while (ptr[l]);
	ptr[k] = '\0';
	_memcpy(ptr, new_substr, new_len);
	replace_substring(ptr + new_len, old_substr, new_substr);
}
/**
 * _strrev - copies and reverses a string
 * @i: str length
 * @s: string
 * Return: i
 */
int _strrev(char *s, int i)
{
	char temp;
	int j;

	i--;
	for (j = 0; j <= i / 2; j++)
	{
		temp = s[j];
		s[j] = s[i - j];
		s[i - j] = temp;
	}
	return (j);
}
/**
 * exists_within - check code
 * @c: character
 * @s: string
 * Return: boolean
 */
int exists_within(char c, char *s)
{
	if (*s == '\0')
		return (c == *s);
	return (c == *s ? 1 : exists_within(c, s + 1));
}
/**
 * del - deletes the first character of a string
 * @s: string
 */
void del(char **s)
{
	int i;

	for (i = 0; (*s)[i]; i++)
		(*s)[i] = (*s)[i + 1];
}
