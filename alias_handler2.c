#include "main.h"

/**
 * check_alias - check code
 * @arr: arguments
 * @alias: alias array
 * @idx: integer
 * Return: none
 */
void check_alias(char ***arr, aliases *alias, int idx)
{
	int i, n;

	for (i = 0; (*arr)[i]; i++)
	{
		n = _getalias(alias, (*arr)[i], idx);
		if (n != -1)
		{
			(*arr)[i] = NULL;
			(*arr)[i] = malloc(_strlen(alias[n].value) + 1);
			_strcpy((*arr)[i], alias[n].value);
		}
	}
}
/**
 * is_valid - chicks valid cmd
 * @comm: cmd
 * @name: given name
 * @arr: given array
 * Return: string
 */
char *is_valid(char *comm, char *name, char **arr)
{
	int i;
	struct stat buf;
	char *path, **path_arr = NULL, *env;

	env = _getenv("PATH");
	if (!env)
	{
		if (!access(comm, X_OK) && stat(comm, &buf) == 0)
			return (comm);
		return (NULL);
	}
	else if (*env == '\0')
	{
		error(name, arr, NULL, 1);
		exit(EXIT_FAILURE);
	}
	else
		path_arr = _strtok(env, ":");
	for (i = 0; path_arr[i]; i++)
	{
		if (!_strstr(comm, "/"))
		{
			path = malloc(_strlen(path_arr[i]) + _strlen(comm) + 3);
			_strcpy(path, path_arr[i]);
			_strcat(path, "/");
			_strcat(path, comm);
		}
		else
			path = malloc(_strlen(comm) + 2), _strcpy(path, comm);
		if (!access(path, X_OK) && stat(path, &buf) == 0)
		{
			_free(path_arr);
			return (path);
		}
		free(path);
	}
	_free(path_arr);
	free(path);
	return (NULL);
}
