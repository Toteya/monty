#include "monty.h"

/**
 * pint_t - Prints the value at the top of the stack
 * @top: Double pointer to the node of the stack
 *
 * Return: Nothing
 */
int pint_t(stack_t **top)
{
	if (*top == NULL)
		return (11);

	printf("%d\n", (*top)->n);
	return (0);
}
