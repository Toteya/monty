#include "monty.h"

/**
 * get_opcode - Checks a string for a monty opcode
 * @str: The string to be checked
 *
 * Return: A string array containing the opcode and the argument if applicable.
 */
op_arg_t *get_opcode(char *str)
{
	char *token, *delim = " ";
	op_arg_t *op_arg;

	op_arg = malloc(sizeof(op_arg_t));
	if (op_arg == NULL)
	{
		fprintf(stderr, "Error: malloc failed.\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);
	op_arg->opcode = _strdup(token);
	if (op_arg->opcode == NULL)
	{
		fprintf(stderr, "Error: malloc failed.\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(NULL, delim);
	if (token != NULL)
	{
		op_arg->arg = _strdup(token);
		if (op_arg->arg == NULL)
		{
			fprintf(stderr, "Error: malloc failed.\n");
			exit(EXIT_FAILURE);
		}
	}
	else
		op_arg->arg = NULL;

	return (op_arg);
}
