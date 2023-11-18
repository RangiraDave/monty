#include "monty.h"

/**
 * free_space - Function to remove white spaces from a string.
 * @str: Pointer to the string.
 *
 * Return: Pointer to space free string.
 */

char *free_space(char *str)
{
	char *end;

	while (isspace((unsigned char)*str))
		str++;

	if (*str == 0)
		return (str);

	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
		end--;

	end[1] = '\0';

	return (str);
}
