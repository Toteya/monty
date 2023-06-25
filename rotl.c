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

	if (*top == NULL || (*top)->next == NULL)
		return (0);

	last = *top;
	p = (*top)->next;
	*top = (*top)->next;
	(*top)->prev = NULL;

	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = last;
	last->prev = p;
	last->next = NULL;

	return (0);
}
