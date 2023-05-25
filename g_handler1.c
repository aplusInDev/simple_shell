#include "main.h"

/**
 * or_handling - handl or
 * @line: arg1
 * @name: arg2
 * @alias: arg3
 * @idx: arg4
 * Return: 0
 */
int or_handling(char *line, char *name, aliases *alias, int *idx)
{
	char **arr, **line_split;
	int break_condition, argc, selector, i = 0;

	line_split = _strtok(line, "|\n");
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok(line_split[i], " \t");
		if (args_count(arr) == 0)
		{
			_free(arr);
			_free(line_split);
			return (error(name, NULL, NULL, 8));
		}
		_free(arr);
	}
	i = 0;
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok(line_split[i], " \t");
		if (_strcmp(arr[0], "alias"))
			check_alias(&arr, alias, *idx);
		break_condition = 0;
		argc = args_count(arr);
		selector = cmd_selector(arr[0], arr, name, alias, idx, line_split, line);
		if (argc > 0 && selector < 0)
			break_condition = _fork(name, arr);
		else if (argc > 0)
			break_condition = selector;
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
 * split_line - read command line
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @idx: integer
 * Return: integer
 */
int split_line(char *line, char *name, aliases *alias, int *idx)
{
	size_t old_len;
	size_t new_len;
	char *temp;

	while (*line == ' ' || *line == '\t')
		del(&line);
	old_len = _strlen(line);
	if (old_len == 1)
		return (0);
	temp = _strstr(line, "#");
	if (temp)
		*temp = '\0';
	replace_substring(line, "&&", "&");
	new_len = _strlen(line);
	if (new_len < old_len)
	{
		replace_substring(line, "&&", "&");
		if (_strlen(line) < new_len)
			return (error(name, NULL, NULL, 7));
		return (and_handling(line, name, alias, idx));
	}
	replace_substring(line, "||", "|");
	new_len = _strlen(line);
	if (new_len < old_len)
	{
		replace_substring(line, "||", "|");
		if (_strlen(line) < new_len)
			return (error(name, NULL, NULL, 8));
		return (or_handling(line, name, alias, idx));
	}
	if (_strstr(line, ";;"))
		return (error(name, NULL, NULL, 9));
	replace_substring(line, "\n", "@");
	return (semi_column_handling(line, name, alias, idx));
}
