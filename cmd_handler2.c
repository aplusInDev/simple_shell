#include "main.h"

/**
 * _read - reads file
 * @line: arg1
 * @args: arg2
 * Return: int
 */
int _read(char **line, char **args)
{
	ssize_t n_read;
	int df;

	df = open(args[1], O_RDONLY);
	if (df == -1)
	{
		error(args[0], args, NULL, 11);
		exit(EXIT_FAILURE);
	}
	*line = _calloc(10240, sizeof(char));
	n_read = read(df, *line, 10240);
	close(df);
	while (**line == ' ' || **line == '\t')
		(*line)++, n_read--;
	(*line)[n_read] = '\0';
	return (n_read);
}
/**
 * args_count - arg counter
 * @args: giving args
 * Return: 0 if fails
 */
int args_count(char **args)
{
	if (args == NULL || *args == NULL)
		return (0);
	return (1 + args_count(args + 1));
}
/**
 * echo - check code
 * @args: giving arg
 * Return: 1 or 0
 */
int echo(char **args)
{
	int status;

	if (!_strcmp(args[0], "echo") && args[1])
	{
		if (!_strcmp(args[1], "$$"))
		{
			to_string(1, getpid());
			write(STDOUT_FILENO, "\n", 1);
			return (1);
		}
		else if (!_strcmp(args[1], "$?"))
		{
			waitpid(getpid() - 1, NULL, 0);
			to_string(1, WEXITSTATUS(status));
			write(STDOUT_FILENO, "\n", 1);
			return (1);
		}
	}
	return (0);
}
/**
 * _free - frees given array
 * @arr: given array
 * Return: nothing
 */
void _free(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return;
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
