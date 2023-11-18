#include "monty.h"

/**
 * main - Entry Point
 * @argc: Number of arguments passed
 * @argv: Array arguments passed
 *
 * Return: 0 on success and -1 otherwise
 */

int main(int argc, char *argv[])
{
	my_stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (read_f(argv[1], &stack) != 0)
	{
		free_s(&stack);

		return (EXIT_FAILURE);
	}
	free_s(&stack);

	return (0);
}
