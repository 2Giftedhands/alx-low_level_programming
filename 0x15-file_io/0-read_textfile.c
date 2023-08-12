#include "main.h"

/**
 * read_textfile - Reads a text file and prints the letters
 * @filename: Textfile to be read.
 * @letters: Number of letters printed.
 *
 * Return: Number of bytes read and printed. It failsor NULL, returns 0.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(letters);
	if (buffer == NULL)
	return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	bytes_read = read(fd, buffer, letters);
	if (bytes_read == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	write(STDOUT_FILENO, buffer, bytes_read);

	free(buffer);
	close(fd);

	return (bytes_read);
}
