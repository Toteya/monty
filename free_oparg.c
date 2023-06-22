#include "monty.h"

/**
 * free_oparg - Frees malloc'ed memory from an op_arg_t struct
 * @op_arg: The struct to be freed
 *
 * Return: Nothing.
 */
void free_oparg(op_arg_t *op_arg)
{
	if (op_arg == NULL)
		return;

	if (op_arg->opcode != NULL)
		free(op_arg->opcode);
	if (op_arg->arg != NULL)
		free(op_arg->arg);

	free(op_arg);
}

