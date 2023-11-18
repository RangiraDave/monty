#include "monty.h"

/**
 * _parser_in - Function to process line into command and args.
 * @space_free: The treamed line from the file.
 * @stack: A pointer to the head of the stack.
 * @counter: Lines counter.
 *
 * Return: Nothing
*/

int _parser_in(char **space_free, unsigned int *counter, my_stack_t **stack)
{
	unsigned int i = 0;
	int found = 0;
	char *opcode = _strtok(*space_free, " \t\n");
	char *args = _strtok(NULL, " \t\n");

	instruction_t instruction_set[] = {
		{"pall", pall},
/*		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},*/
	};

	if (strcmp(opcode, "push") == 0)
	{
		push(stack, *counter, args);
		found = 1;
	}
	for (i = 0; i < sizeof(instruction_set) / sizeof(instruction_set[0]); i++)
	{
		if (strcmp(opcode, instruction_set[i].opcode) == 0)
		{
			instruction_set[i].f(stack, *counter);
			found = 1;
			break;
		}
	}
	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", *counter, opcode);
		return (EXIT_FAILURE);
	}
	return (0);
}
