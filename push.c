#include "monty.h"

/**
 * push - Function to push element to stack.
 * @head: Pointer to the head of the stack.
 * @line: The line  number.
 * @data: Element on that very line.
 *
 * Return: Nothing.
 */

void push(my_stack_t **head, unsigned int line, char *data)
{
	my_stack_t *new_node = malloc(sizeof(my_stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error during allocation\n");
		free_s(head);
		exit(EXIT_FAILURE);
	}
	if (_isint(data))
	{
		int n = (strcmp(data, "0") == 0) ? 0 : atoi(data);

		if ((*head) == NULL)
		{
			new_node->n = n;
			new_node->next = NULL;
			new_node->prev = NULL;
			(*head) = new_node;
		}
		else
		{
			new_node->n = n;
			new_node->next = (*head);
			(*head)->prev = new_node;
			(*head) = new_node;
		}
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		free_s(head);
		exit(EXIT_FAILURE);
	}
}
