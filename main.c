#include "lists.h"
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
	instruction_t instructs[] = {
		{"push", push_t},
		{"pall", pall_t},
		{NULL, NULL}
	};
	char *filename, *line, **op_arg;
	unsigned int line_nr = 0, i = 0;
	stack_t *top;

	top = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = av[1];

	while ((line = next_line(filename)) != NULL)
	{
		line_nr++;
		op_arg = get_opcode(line, line_nr);
		while (instructs[i].opcode != NULL)
		{
			if (strcmp(op_arg[0], instructs[i].opcode) == 0)
				break;
			i++;
		}
		instructs[i].f(&top, atoi(op_arg[1]));
		i = 0;
	}

	return (EXIT_SUCCESS);
}
