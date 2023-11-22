#include "monty.h"

/**
 * sub - Function to substract elements in a stack
 * and appends the result to the top.
 * @stack: A pointer to the stack
 * @line: The line to be executed.
 *
 * Return: Nothing
 */

void sub(my_stack_t **stack, unsigned int line)
{
	my_stack_t *top = *stack;
	my_stack_t *following = top->next;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line);
		free_s(stack);
		exit(EXIT_FAILURE);
	}

	following->n = following->n - top->n;
	following->prev = NULL;
	(*stack) = following;
	free(top);
}
