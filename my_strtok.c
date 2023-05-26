#include "main.h"

/**
 * _strtok - check code
 * @s: string
 * @delim: string
 * Return: tokens set
 */
char *_strtok(char *s, const char *delim)
{
        static char *next_start;
        char *token;

        next_start = s;
        if (!next_start || !*next_start)
                return (NULL);
        token = next_start;
        while (*next_start)
        {
                if (_strchr(delim, *next_start))
                {
                        *next_start++ = '\0';
                        break;
                }
                next_start++;
        }
        return (token);
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
