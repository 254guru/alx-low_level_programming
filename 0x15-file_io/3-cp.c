#include <stdio.h>
#include <errno.h>
#include "main.h"
#include <string.h>

#define BUFFER_SIZE 1024
/**
 * print_usage_and_exit - copies files
 *
 * Return: 0
 */
void print_usage_and_exit()
{
        dprintf(SRDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
}
/**
 * print_error_and_exit - prints error
 * @filename: name of file
 * @message: content of the file
 *
 * Return: 0
 */
void print_error_and_exit(const char *filename, const char *message)
{
        dprintf(STDERR_FILENO, "Error: can't %s %s\n", message, filename);
        exit(98);
}

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
        int file_from, file_to;
        ssize_t bytes_read, bytes_written;
        char buffer[BUFFER_SIZE];

        if (argc != 3)
                print_usage_and_exit();

        file_from = open(argv[1], O_RDONLY);
        if (file_from == -1)
                print_error_and_exit(argv[1], "read from file");

        file_to = open(argv[2] O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_to == -1)
		print_error_and_exit(argv[2], "write to file");

	while ((bytes_read = read(file_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written == -1)
			print_error_and_exit(argv[2], "write to file");
		if (bytes_written < bytes_read)
			print_error_and_exit(argv[2], "write to file");
	}

	if (bytes_read == -1)
		print_error_and_exit(argv[1], "read from file");

	if (close(file_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);

	if (close(file_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);

	return (0);

}
