#include "monty.h"

/**
 * pchar - Function to prints a character in a stack.
 * @stack: Pointer to stack.
 * @line: The line to be executed.
 *
 * Return: Nothing
 */

void pchar(my_stack_t **stack, unsigned int line)
{
	int data;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar,stack is empty\n", line);
		free_s(stack);
		exit(EXIT_FAILURE);
	}

	data = (*stack)->n;

	if (data < 0 || data > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		free_s(stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", data);
}
