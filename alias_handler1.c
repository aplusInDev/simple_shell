#include "main.h"

/**
 * _alias - works with aliases
 * @argc: arg1
 * @args: arg2
 * @name: arg3
 * @alias: arg4
 * @idx: arg5
 * @split: arg6
 * @line: arg7
 * Return:
 */
int _alias(int argc, char **args, char *name,
		aliases *alias, int *idx, char **split, char *line)
{
	char **a;
	int i, j;

	(void) name;
	(void) split;
	(void) line;
	if (argc == 1)
	{
		for (i = 0; *idx && i < *idx; i++)
		{
			print_string(1, alias[i].name), print_string(1, "='");
			print_string(1, alias[i].value), print_string(1, "'\n");
		}
	}
	for (i = 1; i < argc; i++)
	{
		a = _strtok(args[i], "="), j = _getalias(alias, a[0], *idx);
		if (!_strstr(args[i], "="))
		{
			if (j != -1)
			{
				print_string(1, alias[j].name), print_string(1, "='");
				print_string(1, alias[j].value), print_string(1, "'\n");
			} else
				error(name, args, args[i], 10);
		}
		else if (j != -1)
		{
			alias[j].value = malloc(_strlen(a[1]) + 1 + _strlen("''"));
			_strcpy(alias[j].value, a[1]);
		}
		else
		{
			alias[*idx].name = malloc(_strlen(a[0]) + 1);
			alias[*idx].value = malloc(_strlen(a[1]) + 1 + _strlen("''"));
			_strcpy(alias[*idx].name, a[0]);
			_strcpy(alias[*idx].value, a[1]), (*idx)++;
		}
	}
	return (1);
}
/**
 * _getalias - checks for aliases
 * @alias: arg1
 * @var: arg2
 * @idx: arg3
 * Return: i if success, or -1 if fails
 */
int _getalias(aliases *alias, char *var, int idx)
{
	int i;

	for (i = 0; i < idx; i++)
	{
		if (!_strcmp(var, alias[i].name))
			return (i);
	}
	return (-1);
}
