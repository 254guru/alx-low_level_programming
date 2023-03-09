#include "main.h"
#include <stdio.h>

/**
 * is_prime_helper - checks if n is divisible by i
 * @n: parameter to be checked
 * @i: number to determine whether n is prime
 *
 * Return: prime number
 */

int is_prime_helper(int n, int i)
{
	if (n <= 1)
	{
		return (0);
	}
	else if (n % i == 0 && i != 1  && i != n)
	{
		return (0);
	}
	else if (i == n)
	{
		return (1);
	}
	else
	{
		return (is_prime_helper(n, i + 1));
	}
}

/**
 * is_prime_number - checks for a prime number
 * @n: parameter to be checked
 *
 * Return: prime number
 */

int is_prime_number(int n)
{
	return (is_prime_helper(n, 2));
}
