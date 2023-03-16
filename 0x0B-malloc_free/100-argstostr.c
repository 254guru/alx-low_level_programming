#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * *argstostr - concatenates all arguments of your program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: NULL
 */

char *argstostr(int ac, char **av)
{
	int total_length, i, j, str_index;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	total_length = 0;
	for (i = 0; i < ac; i++)
		total_length += strlen(av[i] + 1);

	str = malloc(total_length * sizeof(char));
	if (str == NULL)
		return (NULL);

	str_index = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			str[str_index++] = av[i][j];

		str[str_index++] = '\n';
	}

	str[str_index] = '\0';

	return (str);
}
