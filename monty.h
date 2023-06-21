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
	void (*f)(stack_t **stack, int arg);
} instruction_t;

/* Function Prototypes */
void push_t(stack_t **top, int n);
void pall_t(stack_t **top, int arg);
char *next_line(char *filename);
char **get_opcode(char *line, unsigned int line_nr);
void free_t(stack_t *top);
void free_str_arr(char **argv);

/* Global Variables // Externs */

extern instruction_t instructs[];

#endif /* LISTS_H */
