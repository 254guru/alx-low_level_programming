#include "main.h"

/**
 * read_textfile - reads a textfile and print to posix
 * @filename: the file to read from
 * @letters: number pf letters to read and print
 *
 * Return: 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t bytes_read, written;
	FILE *file;

	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	buf = malloc(letters * sizeof(char));
	if (buf == NULL)
		return (0);

	bytes_read = fread(buf, sizeof(char), letters, file);
	if (bytes_read == 0)
		return (0);

	written = write(STDOUT_FILENO, buf, bytes_read);
	if (written == -1 || written != bytes_read)
		return (0);

	free(buf);
	fclose(file);

	return (bytes_read);
}
