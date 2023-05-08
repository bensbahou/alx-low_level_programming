#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file to append text to
 * @text_content: NULL terminated string to add at the end of the file
 * Return: 1 on success, -1 on failure
 * Failures:
 * - file can not be opened or written
 * - filename is NULL
 * - write fails
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written, length = 0;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length])
			length++;
		bytes_written = write(file_descriptor, text_content, length);
		if (bytes_written == -1)
			return (-1);
	}

	close(file_descriptor);
	return (1);
}
