#include "monty.h"

/**
 * add - Function to add elements of a stack
 * and append the result to the top of the stack.
 * @stack: Name of the stack.
 * @line: The line to be executed.
 *
 * Return: Nothing
 */

void add(my_stack_t **stack, unsigned int line)
{
	my_stack_t *top = *stack;
	my_stack_t *following = top->next;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L %u: can't add, stack too short\n", line);
		free_s(stack);
		exit(EXIT_FAILURE);
	}

	following->n += top->n;
	following->prev = NULL;
	(*stack) = following;
	free(top);
}
