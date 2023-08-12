#include "main.h"

/**
 * create_file - Creates a file
 * @filename: Name of file to be created
 * @text_content: content written in the file.
 *
 * Return: -1 if it fails. 1 if it's successful
 */

int create_file(const char *filename, char *text_content)
{
	int fd, bytes_written, len;

	if (filename == NULL)
	return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
	return (-1);

	if (text_content != NULL)
{
		for (len = 0; text_content[len] != '\0'; len++)
		continue;

	bytes_written = write(fd, text_content, len);
	if (bytes_written == -1)
{
		close(fd);
		return (-1);
	}
	}

	close(fd);
	return (1);
}
