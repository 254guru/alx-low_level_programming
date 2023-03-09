#include "main.h"

/**
 * _pow_recursion - returns a value x raised to the power y
 * @x: main integer
 * @y: power integer
 *
 * Return: integer value
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	else if (y == 0)
	{
		return (1);
	}
	else
	{
		return (x * _pow_recursion(x, y - 1));
	}
}
