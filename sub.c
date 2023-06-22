#include "monty.h"

/**
 * sub_t - Subtracts the top element of the stack from the second
 * element of the stact.
 * @top: Double pointer to the top node of the stack
 * @line_nr: Current line number of the bytecode
 *
 * Return: 0 on success. Otherwise 16 on failure.
 */
int sub_t(stack_t **top, unsigned int line_nr)
{
	stack_t *p;
	(void) line_nr;

	if (*top == NULL || (*top)->prev == NULL)
		return (16);

	p = *top;
	*top = (*top)->prev;
	(*top)->n -= p->n;
	(*top)->next = NULL;
	free(p);

	return (0);
}
