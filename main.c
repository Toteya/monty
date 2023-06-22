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

		status = select_func(&top, op_arg, line_nr);
		if (status != 0)
		{
			print_err(status, line_nr);
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
 *
 * Return: Nothing.
 */
void print_err(int status, unsigned int line_nr)
{
	switch (status)
	{
		case 1:
			fprintf(stderr, "L%u: usage: push integer\n", line_nr);
			break;
		case 2:
			fprintf(stderr, "L%u: unknown instruction <opcode>\n", line_nr);
			break;
	}
}

