#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: Name of file to be appended.
 * @text_content: added content at end of file.
 *
 * Return: -1 if the file does not exist
 * or if it fails. 1 if the file exists.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, bytes_written, length;

	if (filename == NULL)
	return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length] != '\0'; length++)
		continue;

	bytes_written = write(fd, text_content, length);
	if (bytes_written == -1)
	{
		close(fd);
		return (-1);
	}
	}

	close(fd);
	return (1);
}
