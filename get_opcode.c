#include "monty.h"

/**
 * get_opcode - Checks a string for a monty oicode
 * @line: The string to be checked
 *
 * Return: A string array containing the opcode and the argument if applicable.
 */
op_arg_t *get_opcode(char *line)
{
	char *token, *delim = " ";
	op_arg_t *op_arg;

	op_arg = malloc(sizeof(op_arg_t));
	if (op_arg == NULL)
		return (NULL);

	token = strtok(line, delim);

	if (token == NULL)
		token = " ";
	op_arg->opcode = _strdup(token);
	if (op_arg->opcode == NULL)
		return (NULL);

	token = strtok(NULL, delim);
	if (token != NULL)
	{
		op_arg->arg = _strdup(token);
		if (op_arg->arg == NULL)
			return (NULL);
	}
	else
		op_arg->arg = NULL;

	return (op_arg);
}
