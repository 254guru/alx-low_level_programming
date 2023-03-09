#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * is_palindrome_helper - checks if an integer start=end
 * @s: parameter to check
 * @start: character at the beginning of a string
 * @end: last character in a string
 *
 * Return: 1 if it is a palindrome
 */

int is_palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
	{
		return (1);
	}
	else if (s[start] != s[end])
	{
		return (0);
	}
	else
	{
		return (is_palindrome_helper(s, start + 1, end - 1));
	}
}

/**
 * is_palindrome - checks if string is a palindrome
 * @s: parameter to check
 *
 * Return: 1 if it is a palindrome
 */

int is_palindrome(char *s)
{
	int length = strlen(s);

	return (is_palindrome_helper(s, 0, length - 1));

}
