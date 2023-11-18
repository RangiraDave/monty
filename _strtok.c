#include "monty.h"

/**
 * _strtok - Function that splits string according to delimiters.
 * @str: The string to be splitted.
 * @delim: The delimiter to use.
 * Return: An array of strings.
 */

char *_strtok(char *str, const char *delim)
{
	static char *pos_str;
	char *stt;

	if (str != NULL)
		pos_str = str;

	if (pos_str == NULL || *pos_str == '\0')
		return (NULL);

	while (*pos_str != '\0' && strchr(delim, *pos_str) != NULL)
		pos_str++;

	if (*pos_str == '\0')
		return (NULL);

	stt = pos_str;

	while (*pos_str != '\0' && strchr(delim, *pos_str) == NULL)
		pos_str++;

	if (*pos_str != '\0')
	{
		*pos_str = '\0';
		pos_str++;
	}

	return (stt);
}
