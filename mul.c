#include "monty.h"

/**
 * mul_t - multiplies the the top two elements of a stack_t
 * @top: Double pointer to the top node of the stack
 * @line_nr: Current line number of the bytecode file.
 *
 * Return: 0 if successful. Otherwise return 18.
 */
int mul_t(stack_t **top, unsigned int line_nr)
{
	stack_t *p;
	(void) line_nr;

	if (*top == NULL || (*top)->next == NULL)
		return (18);

	p = *top;
	*top = (*top)->next;
	(*top)->n *= p->n;
	(*top)->prev = NULL;
	free(p);

	return (0);
}
