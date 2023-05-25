#include "main.h"

/**
 * and_handling - check code
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @idx: integer
 * Return: integer
 */
int and_handling(char *line, char *name, aliases *alias, int *idx)
{
	char **arr, **line_split;
	int break_condition, argc, selector, i = 0;

	line_split = _strtok(line, "&\n");
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok(line_split[i], " \t");
		if (args_count(arr) == 0)
		{
			_free(arr);
			_free(line_split);
			return (error(name, NULL, NULL, 7));
		}
		_free(arr);
	}
	for (i = 0; line_split[i]; i++)
	{
		break_condition = 0;
		arr = _strtok(line_split[i], " \t");
		if (_strcmp(arr[0], "alias"))
			check_alias(&arr, alias, *idx);
		argc = args_count(arr);
		selector = cmd_selector(arr[0], arr, name, alias, idx, line_split, line);
		if (argc > 0 && selector < 0)
			break_condition = 1 - _fork(name, arr);
		else if (argc > 0)
			break_condition = 1 - selector;
		if (break_condition)
		{
			_free(arr);
			break;
		}
		_free(arr);
	}
	_free(line_split);
	return (break_condition ? 0 : EXIT_FAILURE);
}
/**
 * semi_column_handling - check code
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @idx: integer
 * Return: integer
 */
int semi_column_handling(char *line, char *name, aliases *alias, int *idx)
{
	char **arr, **line_split;
	int argc, i = 0, frk = 0;

	line_split = _strtok(line, ";\n");
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok(line_split[i], " \t");
		if (args_count(arr) == 0)
		{
			_free(arr);
			_free(line_split);
			return (error(name, NULL, NULL, 9));
		}
		_free(arr);
	}
	_free(line_split);
	line_split = _strtok(line, "@;\n");
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok(line_split[i], " \t'");
		if (_strstr(line, "alias"))
			check_alias(&arr, alias, *idx);
		argc = args_count(arr);
		if (argc > 0 && cmd_selector(arr[0], arr,
					name, alias, idx, line_split, line) < 0)
			_fork(name, arr);
		else if (!_strstr(line, "@") && argc == 0)
		{
			_free(line_split);
			_free(arr);
			return (error(name, NULL, NULL, 9));
		}
		_free(arr);
	}
	_free(line_split);
	return (frk ? EXIT_FAILURE : 0);
}
