#include "monty.h"

/**
 * _isint - Function to check whether a string is int or not.
 * @str: The string to be checked.
 *
 * Return: True for if int and otherwise False.
 */

bool _isint(const char *str)
{
	if (*str == '-')
		str++;

	if (*str == '\0')
		return (false);

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}
