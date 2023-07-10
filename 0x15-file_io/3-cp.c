#include "main.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	copy_file(argv[1], argv[2]);
	return (0);
}
/**
 * copy_file - copies content of one file to another
 * @src: source file
 * @dest: destination file
 *
 * Return: void
 */

void copy_file(const char *src, const char *dest)
{
	int i, j, k;
	char buf[1024];

	i = open(src, O_RDONLY);
	if (i == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		exit(98);
	}
	j = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (j == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
		exit(99);
	}
	while ((k = read(i, buf, 1024)) > 0)
	{
		if (write(j, buf, k) != k)
		{
			dprintf(STDERR_FILENO, "Error: Can't write %s\n", dest);
			exit(99);
		}
	}
	if (k == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		exit(98);
	}
	if (close(j) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", j);
		exit(100);
	}
	if (close(i) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", i);
		exit(100);
	}

}
