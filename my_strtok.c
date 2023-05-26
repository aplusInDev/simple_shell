#include "main.h"

/**
 * _strtok - check code
 * @s: string
 * @delim: string
 * Return: tokens set
 */
char **_strtok(char *s, char *delim)
{
	char **tokens;
	size_t j = 0, i, len = _strlen(s) + 1;
	int found = 1, k = 0;

	tokens = (char **)_calloc(len * sizeof(char *), sizeof(char));
	*tokens = (char *)_calloc(len, sizeof(char));
	if (!*tokens)
		free(tokens);
	for (i = 0; s[i]; i++)
	{
		if (exists_within(s[i], delim))
		{
			if (!found)
			{
				tokens[k++][j] = '\0';
				tokens[k] = (char *)_calloc(len, sizeof(char));
				if (!tokens[k])
					_free(tokens);
			}
			found = 1;
			j = 0;
		}
		else
		{
			tokens[k][j++] = s[i];
			found = 0;
		}
	}
	if (found)
	{
		free(tokens[k]);
		tokens[k] = NULL;
	}
	else
		tokens[k][j] = '\0';
	return (tokens);
}
/**
 * _calloc - allocates memory
 *
 * @nmemb: arg1
 * @size: arg2
 *
 * Return: pointer if success or NULL if fails
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < size * nmemb; i++)
		ptr[i] = 0;
	return (ptr);
}
