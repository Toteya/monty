#include "monty.h"

/**
 * _div_t - Divides the second top element by the top element
 * @top: Double pointer to the top node of the stack
 * @line_nr: Current line number of the bytecode
 *
 * Return: On success return 0. Otherwise return 17.
 */
int _div_t(stack_t **top, unsigned int line_nr)
{
	stack_t *p;
	(void) line_nr;

	if (*top == NULL || (*top)->next == NULL)
		return (17);
	if ((*top)->n == 0)
		return (170);

	p = *top;
	*top = (*top)->next;
	(*top)->n /= p->n;
	(*top)->prev = NULL;
	free(p);

	return (0);
}
