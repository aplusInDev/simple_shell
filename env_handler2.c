#include "main.h"

/**
 * env - env
 * @argc: arg1
 * @args: arg2
 * @name: arg3
 * @alias: arg4
 * @idx: arg5
 * @split: arg6
 * @line: arg7
 * Return: 1
 */
int env(int argc, char **args, char *name,
		aliases *alias, int *idx, char **split, char *line)
{
	int i;

	(void) argc;
	(void) args;
	(void) name;
	(void) split;
	(void) alias;
	(void) idx;
	(void) line;
	for (i = 0; environ[i]; i++)
	{
		print_string(1, environ[i]);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}
/**
 * _getenv -  gets an environment
 * @name: given param
 * Return: tmp if success, or NULL it fails
 */
char *_getenv(char *name)
{
	int i;
	char *tmp;

	for (i = 0; environ[i]; i++)
	{
		if (!_strncmp(name, environ[i], _strlen(name)))
		{
			tmp = _strstr(environ[i], "=");
			tmp++;
			return (tmp);
		}
	}
	return (NULL);
}
/**
 * unset - unset
 * @argc: arg1
 * @args: arg2
 * @name: arg3
 * @alias: arg4
 * @idx: arg5
 * @split: arg6
 * @line: arg7
 * Return: 1
 */
int unset(int argc, char **args, char *name,
		aliases *alias, int *idx, char **split, char *line)
{
	int i;

	(void) alias;
	(void) idx;
	(void) split;
	(void) line;
	if (argc != 2)
	{
		error(name, args, NULL, 5);
		return (0);
	}
	else if (_getenv(args[1]) == NULL)
	{
		error(name, args, NULL, 6);
		return (0);
	}
	else
	{
		for (i = 0; environ[i]; i++)
		{
			if (_strncmp(environ[i], args[1], _strlen(args[1])) == 0)
			{
				environ[i] = NULL;
				break;
			}
		}
		return (1);
	}
}
