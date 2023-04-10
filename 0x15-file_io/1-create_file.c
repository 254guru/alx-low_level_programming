#include "main.h"
#include <string.h>

/**
 * create_file - function that creates files
 * @filename: pointer to the name of the file to crete
 * @text_content: NULL terminated string to write to the file
 *
 * Return: file
 */

int create_file(const char *filename, char *text_content)
{
	int fd, bytes_written;
	mode_t mode = S_IRUSR | S_IWUSR;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY |O_TRUNC, mode);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		bytes_written = write(fd, text_content, strlen(text_content));
		if (bytes_written == -1)
			return (-1);
	}

	close(fd);
	return (1);
}
