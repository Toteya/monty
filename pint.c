#include "monty.h"

/**
 * pint_t - Prints the value at the top of the stack
 * @top: Double pointer to the node of the stack
 * @line_nr: The current line number
 *
 * Return: Nothing
 */
int pint_t(stack_t **top, unsigned int line_nr)
{
	(void) line_nr;

	if (*top == NULL)
		return (11);

	printf("%d\n", (*top)->n);
	return (0);
}
