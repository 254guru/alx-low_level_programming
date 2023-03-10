#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints its name
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	printf("argc = %d\n", argc);
	printf("%s\n", argv[0]);
	return (0);
}
