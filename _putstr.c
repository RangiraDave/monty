#include "monty.h"

/**
 * pstr - Function to print a string in a stack
 * starting from the top.
 * @stack: A pointer to the stack.
 * @line: The line tobe executed.
 *
 * Return: Nothing
 */

void pstr(my_stack_t **stack, unsigned int line)
{
	my_stack_t *top = *stack;

	int i = 0;
	char str[1024];

	(void) line;

	if ((*stack) == NULL)
		printf("\n");

	while (top != NULL)
	{
		int data = top->n;

		if (data == 0 || (data < 1 || data > 127))
		{
			break;
		}

		str[i] = (char)data;

		top = top->next;
		i++;
	}

	str[i] = '\0';

	printf("%s\n", str);
}
