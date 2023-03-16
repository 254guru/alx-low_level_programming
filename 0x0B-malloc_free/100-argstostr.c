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
	int total_length = 0, i, current_index;
	char *result;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		total_length += strlen(av[i]) + 1;
	}

	result = malloc(sizeof(char) * total_length);

	if (result == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		strcpy(result + current_index, av[i]);
		current_index += strlen(av[i]);
		*(result + current_index) = '\n';
		current_index++;
	}

	*(result + current_index) = '\0';

	return (result);
}
