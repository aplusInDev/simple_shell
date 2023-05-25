#include "main.h"

/**
 * exit_function - exit function
 * @n: arg1
 * @args: arg2
 * @name: arg3
 * @alias: arg4
 * @idx: arg5
 * @split: arg6
 * @line: arg7
 * Return: 1
 */
int exit_function(int n, char **args, char *name,
		aliases *alias, int *idx, char **split, char *line)
{
	int i = 0;

	(void) alias;
	(void) idx;
	for (; n > 1 && args[1][i]; i++)
	{
		if (args[1][i] < '0' || args[1][i] > '9')
		{
			error(name, args, NULL, 2);
			return (0);
		}
	}
	if (n > 1)
		i = _atoi(args[1]);
	_free(split);
	free(line);
	_free(args);
	exit(i);
	return (1);
}
/**
 * change_dir - change dir
 * @argc: arg1
 * @args: arg2
 * @name: arg3
 * @alias: arg4
 * @idx: arg5
 * @split: arg6
 * @line: arg7
 * Return: 1
 */
int change_dir(int argc, char **args, char *name,
		aliases *alias, int *idx, char **split, char *line)
{
	char *path, *temp;

	(void) alias;
	(void) idx;
	(void) line;
	(void) split;
	path = argc == 1 || _strcmp(args[1], "~") == 0 ? _getenv("HOME") : args[1];
	if (chdir(path) < 0)
	{
		error(name, args, path, 3);
		return (0);
	}
	temp = _getenv("PWD");
	_strcpy(temp, path);
	if (argc == 1)
	{
		print_string(1, path);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}
/**
 * export - export
 * @argc: arg1
 * @args: arg2
 * @name: arg3
 * @alias: arg4
 * @idx: arg5
 * @split: arg6
 * @line: arg7
 * Return: 1
 */
int export(int argc, char **args, char *name,
		aliases *alias, int *idx, char **split, char *line)
{
	int i = 0;
	char *temp;

	(void) alias;
	(void) idx;
	(void) split;
	(void) line;
	if (argc != 3)
	{
		error(name, args, NULL, 4);
		return (0);
	}
	else
	{
		temp = _getenv(args[1]);
		if (temp)
			_strcpy(temp, args[2]);
		else
		{
			while (environ[i])
				i++;
			environ[i] = malloc(_strlen(args[1]) + _strlen(args[2]) + 3);
			_strcat(environ[i], args[1]);
			_strcat(environ[i], "=");
			_strcat(environ[i], args[2]);
			environ[++i] = NULL;
		}
		return (1);
	}
}
