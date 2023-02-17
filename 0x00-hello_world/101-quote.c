#include  <unistd.h>

/**
 * main - Entry
 *
 * Return: Always 1 (on error)
 */

int main(void)
{
	const char msg[] = "and that piece of art is useful\""
	       			" - Dora Korpar, 2015-10-19\n";
	ssize_t len = sizeof(msg) - 1;

	ssize_t n = write(2, msg, len);

	return (n != len);
}
