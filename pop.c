#include "monty.h"

/**
 * pop - Removes the top element in the stack
 * @stack: The Pointer to the stack
 * @line_number: line number of the executing line
 * Return: Nothing
 */

void pop(my_stack_t **stack, unsigned int line_number)
{
	my_stack_t *temp = (*stack);


	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_s(stack);
		exit(EXIT_FAILURE);
	}
	(*stack) = temp->next;
	if ((*stack) != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
