#include "monty.h"

/**
 * rotl_t - Rotates the stack
 * @top: Double pointer to the top of th stack
 * @line_nr: Current line number of the monty bytecode
 *
 * Return: Always 0.
 */
int rotl_t(stack_t **top, unsigned int line_nr)
{
	stack_t *p, *last;
	(void) line_nr;

	if (*top == NULL || (*top)->prev == NULL)
		return (0);

	last = *top;
	p = (*top)->prev;
	*top = (*top)->prev;
	(*top)->next = NULL;

	while (p->prev != NULL)
	{
		p = p->prev;
	}
	p->prev = last;
	last->next = p;
	last->prev = NULL;

	return (0);
}
