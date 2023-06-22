#include "monty.h"

/**
 * pint_t - Prints the value at the top of the stack
 * @top: Double pointer to the node of the stack
 * @line_nr: The current line number
 *
 * Return: Nothing
 */
void pint_t(stack_t **top, unsigned int line_nr)
{
	if (*top != NULL)
	{
		printf("%d\n", (*top)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_nr);
		exit(EXIT_FAILURE);
	}
}
