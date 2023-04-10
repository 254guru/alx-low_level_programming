#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX stdout
 * @filename: pointer to a constant string
 * @letters: max number of characters to read
 *
 * Return: bytes read
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t bytes_read, bytes_written;
	FILE *file;

	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	buffer = malloc(letters * sizeof(char));
	if (buffer == NULL)
		return (0);

	bytes_read = fread(buffer, sizeof(char), letters, file);
	if (bytes_read == 0)
		return (0);

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
		return (0);

	free(buffer);
	fclose(file);

	return (bytes_read);
}
