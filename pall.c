#include "monty.h"

/**
 * pall - Function to print stack contents.
 * @stack: Pointer to the stack.
 * @line: The line to be printed.
 *
 * Return: Nothing.
 */

void pall(my_stack_t **stack, unsigned int line)
{
	my_stack_t *pointer = (*stack);
	int counter = 0;
	(void) line;
	(void) counter;
	(void) stack;

	if (pointer != NULL)
	{
		while (pointer != NULL)
		{
			printf("%d\n", pointer->n);
			counter++;
			pointer = pointer->next;
		}
	}
}
