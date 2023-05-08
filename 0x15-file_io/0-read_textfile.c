#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the posix
 * @filename: pointer to a constant string
 * @letters: maximum no of characters to read from the file
 *
 * Return: 0 if file can't open or NULL
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
