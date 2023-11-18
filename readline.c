#include "monty.h"

/**
 * read_l - Function to read a line from a file.
 * @lineptr: Pointer to the line.
 * @n: Length of the line buffer.
 * @f_name: The name of the file to read from.
 *
 * Return: Number of characters read and -1 or EOF on error
 */

ssize_t read_l(char **lineptr, size_t *n, FILE *f_name)
{
	size_t i = 0;
	int c;
	size_t  size = *n + 128;
	char ptr[1024];

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	if (*lineptr != NULL)
	{
		while ((c = fgetc(f_name)) != EOF)
		{
			if (i == *n - 1)
			{
				if (ptr == NULL)
					return (-1);
				*lineptr = ptr;
				*n = size;
			}

			(*lineptr)[i++] = c;
			if (c == '\n')
			{
				(*lineptr)[i] = '\0';
				return (i);
			}
		}
	}
	if (i == 0)
		return (-1);
	(*lineptr)[i] = '\0';
	return (i);
}
