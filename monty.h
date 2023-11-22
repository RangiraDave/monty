#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} my_stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(my_stack_t **stack, unsigned int line);
} instruction_t;

extern my_stack_t *temp;
extern int data;


char *_strtok(char *str, const char *delim);
void push(my_stack_t **head, unsigned int line, char *data);
void free_s(my_stack_t **stack);
void pall(my_stack_t **stack, unsigned int line);
int read_f(char *filename, my_stack_t **stack);
ssize_t read_l(char **lineptr, size_t *n, FILE *f_name);
int _parser_in(char **space_free, unsigned int *counter, my_stack_t **stack);
char *free_space(char *str);
void pint(my_stack_t **stack, unsigned int line);
bool _isint(const char *str);
void pop(my_stack_t **stack, unsigned int line);
void swap(my_stack_t **stack, unsigned int line);
void add(my_stack_t **stack, unsigned int line);
void nop(my_stack_t **head, unsigned int line);

void sub(my_stack_t **stack, unsigned int line);
void divi(my_stack_t **stack, unsigned int line);
void mul(my_stack_t **stack, unsigned int line);
void mod(my_stack_t **stack, unsigned int line);
void pchar(my_stack_t **head, unsigned int line);
void pstr(my_stack_t **stack, unsigned int line);

#endif
