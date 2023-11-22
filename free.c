#include "monty.h"

/**
 * free_s - Function to free a stack once.
 * @stack: A pointer to the head of the stack.
 *
 * Return: Nothing.
 */

void free_s(my_stack_t **stack)
{
	my_stack_t *temp;

	if ((*stack) != NULL)
	{
		while (*stack != NULL)
		{
			temp = (*stack);
			(*stack) = (*stack)->next;
			free(temp);
		}
	}
}
