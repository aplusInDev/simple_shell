#include "main.h"

/**
 * cmd_selector - cmd selector
 * @cmd: arg1
 * @args: arg2
 * @name: arg3
 * @alias: arg4
 * @idx: arg5
 * @split: arg6
 * @line: arg7
 * Return: -1 if fails
 */
int cmd_selector(const char *cmd, char **args,
		char *name, aliases *alias, int *idx, char **split, char *line)
{
	cmd_executer executers[] = {
		{"exit", exit_function},
		{"cd", change_dir},
		{"setenv", export},
		{"unsetenv", unset},
		{"env", env},
		{"alias", _alias},
		{NULL, NULL}
	};
	int j = 0;

	while (executers[j].exe_func != NULL && _strcmp(cmd, executers[j].cmd) != 0)
		j++;
	if (executers[j].exe_func != NULL)
		return (executers[j].exe_func(args_count(args), args,
					name, alias, idx, split, line));
	return (-1);
}
/**
 * _fork - make process
 * @name: arg1
 * @arr: arg2
 * Return: r value
 */
int _fork(char *name, char **arr)
{
	pid_t p;
	int r = 1;
	char *path = NULL;

	path = is_valid(arr[0], name, arr);
	if (path != NULL)
	{
		p = fork();
		if (p == 0)
		{
			r = execmd(arr, name, path);
			exit(0);
		}
		if (p > 0)
			waitpid(p, NULL, 0);
		free(path);
	}
	else
	{
		error(name, arr, NULL, 1);
		r = 0;
	}
	return (r);
}
/**
 * execmd - executes command
 * @arr: arg1
 * @name: given name
 * @path: given path
 * Return: r value
 */
int execmd(char **arr, char *name, char *path)
{
	int e = 0, r = 1;
	char *env;

	(void) name;
	if (arr)
	{
		e = echo(arr);
		if (e == 0 && arr[1] && arr[1][0] == '$')
		{
			env = _getenv(arr[1] + 1);
			if (env)
			{
				arr[1] = malloc(sizeof(env));
				_strcpy(arr[1], env);
			}
			else
			{
				write(STDOUT_FILENO, "\n", 1);
				return (1);
			}
		}
		if (e == 0)
			if (execve(path, arr, environ) == -1)
				r = 0;
		_free(arr);
	}
	return (r);
}
/**
 * _getline - gets line from standard input
 * @line: passed line
 * Return: printed character count
 */
int _getline(char **line)
{
	int ch_writen;

	*line = _calloc(10240, sizeof(char));
	ch_writen = read(STDIN_FILENO, *line, 10240);
	(*line)[ch_writen] = '\0';
	return (ch_writen);
}
