#include <stdio.h>
/**
 * main - Entry
 * Return: Always 0
 */
int main(void)
{
	char a;
	int b;
	long int c;
	long long int d;
	float e;

	printf("size of a char: %lu bytes\n", sizeof(a));
	printf("size of an int: %lu bytes\n", sizeof(b));
	printf("size of a long int: %lu bytes\n", sizeof(c));
	printf("size of a long long int: %lu bytes\n", sizeof(d));
	printf("size of a float: %lu bytes\n", sizeof(e));
	return (0);
}
