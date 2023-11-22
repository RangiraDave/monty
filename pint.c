#include "monty.h"

/**
 * pint - Fucntion that prints an element that is
 * at the top of a stack.
 * @stack: A Pointer to the stack.
 * @line: The line to be executed.
 *
 * Return: Nothing
 */

void pint(my_stack_t **stack, unsigned int line)
{
	if ((*stack) != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
		fprintf(stderr, "L%u: can't pint, stack is empty.\n", line);
}
