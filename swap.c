#include "monty.h"

/**
 * swap - Function to swaps the top two elements in a stack.
 * @stack: A pointer to the stack.
 * @line: The line to be executed.
 *
 * Return: Nothing
 */

void swap(my_stack_t **stack, unsigned int line)
{
	my_stack_t *top = (*stack);
	my_stack_t *following = top->next;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L %u: can't swap, stack too short\n", line);
		free_s(stack);
		exit(EXIT_FAILURE);
	}

	top->next = following->next;
	top->prev = following;
	following->prev = NULL;
	following->prev = top;
	following->next->prev = top;

	if (top == (*stack))
		(*stack) = following;
}
