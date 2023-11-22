#include "monty.h"

/**
 * mul - Function to multiply elements in stack
 * and append the result to the top.
 * @stack: A pointer to the stack.
 * @line: The line to be executed.
 *
 * Return: Nothing
 */

void mul(my_stack_t **stack, unsigned int line)
{
	my_stack_t *top = *stack;
	my_stack_t *following = top->next;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		free_s(stack);
		exit(EXIT_FAILURE);
	}

	following->n = following->n * top->n;
	following->prev = NULL;
	(*stack) = following;
	free(top);
}
