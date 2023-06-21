#include "lists.h"

int opcode_valid(char *str);
int is_numeric(char *str);

/**
 * get_opcode - Checks a string for a monty opcode
 * @str: The string to be checked
 * @line_nr: The current line number of the bytecode
 *
 * Return: A string array containing the opcode and the argument if applicable.
 */
char **get_opcode(char *str, unsigned int line_nr)
{
	unsigned int i;
	char *opcode, *arg = "", *token, *delim = " ";
	char **op_arg;

	op_arg = malloc(sizeof(char *) * 2);
	if (op_arg == NULL)
	{
		fprintf(stderr, "Error: malloc failed.\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);
	if (!opcode_valid(token))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_nr, token);
		exit(EXIT_FAILURE);
	}
	opcode = malloc(sizeof(char) * strlen(token));
	if (opcode == NULL)
	{
		fprintf(stderr, "Error: malloc failed.\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= strlen(token); i++)
		opcode[i] = token[i];
	op_arg[0] = opcode;

	if (strcmp(opcode, "push") == 0)
	{
		token = strtok(NULL, delim);
		if (!is_numeric(token))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_nr);
			exit(EXIT_FAILURE);
		}
		arg = malloc(sizeof(char) * strlen(token));
		if (arg == NULL)
		{
			fprintf(stderr, "Error: malloc failed.\n");
			exit(EXIT_FAILURE);
		}
		for (i = 0; i <= strlen(token); i++)
			arg[i] = token[i];
	}
	op_arg[1] = arg;

	return (op_arg);
}

/**
 * opcode_valid - Checks if a string is a valid monty opcode
 * @str: The string to be checked
 *
 * Return: 1 if valid. Otherwise return 0.
 */
int opcode_valid(char *str)
{
	unsigned int i;
	char *opcodes[] = {
		"push",
		"pall",
		NULL
	};

	for (i = 0; str && opcodes[i] != NULL; i++)
	{
		if (strcmp(str, opcodes[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * is_numeric - Checks if a string contains only numeric characters
 * @str: The string to be checked
 *
 * Return: 1 if the string is purely numeric. Otherwise return 0.
 */
int is_numeric(char *str)
{
	if (!str)
		return (0);

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
