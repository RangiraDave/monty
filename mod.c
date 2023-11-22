#include "monty.h"

/**
 * mod - Function to find modulus of the elements in the
 * stack and append the result to the top.
 * @stack: A pointer the stack.
 * @line: The line to be executed.
 *
 * Return: Nothing
 */

void mod(my_stack_t **stack, unsigned int line)
{
	my_stack_t *top = *stack;
	my_stack_t *following = top->next;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		free_s(stack);
		exit(EXIT_FAILURE);
	}

	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		free_s(stack);
		exit(EXIT_FAILURE);
	}

	following->n = following->n % top->n;
	following->prev = NULL;
	(*stack) = following;
	free(top);
}
