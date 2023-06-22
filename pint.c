#include "monty.h"

/**
 * pint_t - Prints the value at the top of the stack
 * @top: Double pointer to the node of the stack
 * @arg: Unused variable. Needed to keep function prototypes consistent
 *
 * Return: Nothing
 */
void pint_t(stack_t **top, int arg)
{
	(void) arg;

	if (*top != NULL)
	{
		printf("%d\n", (*top)->n);
	}
	else
	{
		fprintf(stderr, "L<line_number>: can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
}
