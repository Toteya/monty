#ifndef LISTS_H
#define LISTS_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Data Structures */

/**
 * struct stack_s - doubly linke list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Descriprtion: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: The function to the handle the opcode
 *
 * Description: opcode and its function for
 * stacks and queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	int (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct op_arg_s - opcode and argument
 * @opcode - The (supposed) opcode
 * @arg - The argument to the opcode
 *
 * Description: An opcode and its argument read from
 * a monty bytecode file
 */
typedef struct op_arg_s
{
	char *opcode;
	char *arg;
} op_arg_t;


/* Function Prototypes */
void push_t(stack_t **top, int n);
int pall_t(stack_t **top, unsigned int line_nr);
int pint_t(stack_t **top, unsigned int line_nr);
int pop_t(stack_t **top, unsigned int line_nr);
int swap_t(stack_t **top, unsigned int line_nr);
int add_t(stack_t **top, unsigned int line_nr);
int nop_t(stack_t **top, unsigned int line_nr);

char *next_line(char *filename, int p);
void free_t(stack_t *top);
void free_oparg(op_arg_t *op_arg);
char *_strdup(char *str);
op_arg_t *get_opcode(char *line);
int is_numeric(char *str);
int select_func(stack_t **top, op_arg_t *op_arg, unsigned int line_nr);
void print_err(int status, unsigned int line_nr);

/* Global Variables // Externs */

extern instruction_t instructs[];

#endif /* LISTS_H */
