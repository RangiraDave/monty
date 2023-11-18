#include "monty.h"

/**
* read_f - Function to Read lines from a file.
* @filename: Name of the file to read from.
* @stack: Pointer to stack.
*
* Return: Nothing
*/

int read_f(char *filename, my_stack_t **stack)
{
	char *space_free, *line = NULL;
	ssize_t n_read;
	size_t n = 0;
	FILE *file = fopen(filename, "r");
	unsigned int line_nbr = 0;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}
	while ((n_read = read_l(&line, &n, file)) != -1)
	{
		line_nbr++;
		if (line[n_read - 1] == '\n' && n_read > 0)
			line[n_read - 1] = '\0';

		if (line[n_read - 2] == '$')
			line[n_read - 2] = ' ';
		space_free = free_space(line);
		if (n_read == 0 || *space_free == '\0' || space_free == NULL)
		{
			free(space_free);
			return (EXIT_FAILURE);
		}
		else
		{
			if (space_free[0] != '#')
			{
				if (_parser_in(&space_free, &line_nbr, stack) != 0)
				{
					free(space_free);
					return (EXIT_FAILURE);
				}
			}
		}
	}
	free(space_free);
	fclose(file);
	return (0);
}
