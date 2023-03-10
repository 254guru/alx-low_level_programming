#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the number of arguments passed
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	printf("%d\n", argc - 1);
	(void) argv;
	return (0);
}
