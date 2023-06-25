#include "monty.h"
#include <stdio.h>

/**
 * select_func - Selects the correct function according to the
 * given monty opcode
 * @op_arg: op_arg_t struct containing the opcode and argument (if any)
 * @top: Double pointer to the head of a stack
 * @mode: Pointer to the mode of operation, i.e. STACk or QUEUE (LIFO, FIFO)
 *
 * Return: 0 on success. Otherwise return the approriate status code
 */
int select_func(stack_t **top, op_arg_t *op_arg, int *mode)
{
	unsigned int i;
	instruction_t instructs[] = {
		{"pint", pint_t},
		{"pall", pall_t},
		{"pop", pop_t},
		{"swap", swap_t},
		{"add", add_t},
		{"nop", nop_t},
		{"sub", sub_t},
		{"div", _div_t},
		{"mul", mul_t},
		{"mod", mod_t},
		{"pchar", pchar_t},
		{"pstr", pstr_t},
		{"rotl", rotl_t},
		{"rotr", rotr_t},
		{NULL, NULL}
	};
	if (strcmp(op_arg->opcode, "queue") == 0)
		*mode = QUEUE_MODE;
	else if (strcmp(op_arg->opcode, "stack") == 0)
		*mode = STACK_MODE;
	else if (strcmp(op_arg->opcode, "push") == 0)
	{
		if (is_numeric(op_arg->arg)) /* Check if argument is numeric */
			push_t(top, atoi(op_arg->arg), *mode);
		else
			return (1);
	}
	else if (strcmp(op_arg->opcode, "") != 0)
	{
		for (i = 0; instructs[i].opcode != NULL; i++)
		{
			if (strcmp(op_arg->opcode, instructs[i].opcode) == 0)
				return (instructs[i].f(top));
		}
		return (2);
	}
	return (0);
}
