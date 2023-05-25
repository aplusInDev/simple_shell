#include "main.h"

/**
 * main - checks code
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 (success)
 */
int main(int ac, char **av)
{
	aliases a;
	int i = 0, v = 0;
	char *input = NULL, *n = av[0];

	(void) ac;
	a.name = NULL;
	a.value = NULL;
	while (1)
	{
		if (isatty(0) && ac == 1)
			write(STDOUT_FILENO, "$ ", 2);
		if (ac == 1 && _getline(&input) <= 0)
		{
			free(input);
			if (isatty(0))
				write(STDOUT_FILENO, "\n", 1);
			exit(v);
		}
		else if (ac != 1 && _read(&input, av) <= 0)
		{
			free(input);
			if (isatty(0))
				write(STDOUT_FILENO, "\n", 1);
			exit(v);
		}
		if (*input != '\0' && _strcmp(input, "\n"))
		{
			error(n, NULL, NULL, 0);
			v = split_line(input, n, &a, &i);
		}
		free(input);
		if (ac != 1)
			return (0);
	}
	return (0);
}
