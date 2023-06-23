#include "monty.h"
#include <stdio.h>

/**
 * main - Monty bytecode interpreter
 * @ac: Number of command line arguments
 * @av: Command line argument vector
 *
 * Return: EXIT STATUS
 */
int main(int ac, char **av)
{
	char *filename, *line;
	unsigned int line_nr = 0;
	stack_t *top = NULL;
	op_arg_t *op_arg = NULL;
	int status = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = av[1];

	while ((line = next_line(filename, 0)) != NULL)
	{
		line_nr++;
		op_arg = get_opcode(line);
		if (op_arg == NULL)
		{
			fprintf(stderr, "Error: malloc failed.\n");
			free(line);
			free(top);
			exit(EXIT_FAILURE);
		}
		status = select_func(&top, op_arg, line_nr);
		if (status != 0)
		{
			print_err(status, line_nr, op_arg->opcode);
			next_line(filename, 1); /* close the open files */
			free(line);
			free_oparg(op_arg);
			free(top);
			exit(EXIT_FAILURE);
		}
		free(line);
		free_oparg(op_arg);
	}
	free_t(top);

	return (EXIT_SUCCESS);
}

/**
 * print_err - Prints a message to STDERR corresponding to the status code
 * @status: Integer status code
 * @line_nr: The current line number of the monty bytecode
 * @opcode: The monty opcode that failed
 *
 * Return: Nothing.
 */
void print_err(int status, unsigned int line_nr, char *opcode)
{
	switch (status)
	{
		case 1:
			fprintf(stderr, "L%u: usage: push integer\n", line_nr);
			break;
		case 2:
			fprintf(stderr, "L%u: unknown instruction %s\n", line_nr, opcode);
			break;
		case 11:
			fprintf(stderr, "L%u: can't pint, stack empty\n", line_nr);
			break;
		case 12:
			fprintf(stderr, "L%u: can't pop an empty stack\n", line_nr);
			break;
		case 13:
			fprintf(stderr, "L%u: can't swap, stack too short\n", line_nr);
			break;
		case 14:
			fprintf(stderr, "L%u: can't add, stack too short\n", line_nr);
			break;
		case 16:
			fprintf(stderr, "L%u: can't sub, stack too short\n", line_nr);
			break;
		case 17:
			fprintf(stderr, "L%u: can't div, stack too short\n", line_nr);
			break;
		case 170:
			fprintf(stderr, "L%u: division by zero\n", line_nr);
			break;
		case 18:
			fprintf(stderr, "L%u: can't mul, stack too short\n", line_nr);
			break;
	}
}

