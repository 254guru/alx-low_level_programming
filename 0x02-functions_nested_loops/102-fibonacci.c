#include <stdio.h>

/**
 * main - prints first 50 fibonacci numbers
 *
 * Return: always 0
 */

int main(void)
{
	int a = 1;
	int b = 2;
	int c;
	int i;

	printf("%d, %d, ", a, b);
	for (i = 0; i < 48; i++)
	{
		c = a + b;
		printf("%d, ", c);
		a = b;
		b = c;
	}

	printf("\n");
	return (0);
}
