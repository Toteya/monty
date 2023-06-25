#include "monty.h"

/**
 * swap_t - Swaps the top two elements of a stack_t
 * @top: Double pointer the top node of the stack
 * @line_nr: The current line number of the bytecode
 *
 * Return: Nothing
 */
int swap_t(stack_t **top, unsigned int line_nr)
{
	stack_t *p;
	(void) line_nr;

	if (*top == NULL || (*top)->next == NULL)
		return (13);

	p = *top;
	*top = (*top)->next;
	(*top)->prev = p->prev;
	p->next = (*top)->next;
	(*top)->next = p;
	p->prev = *top;

	return (0);
}
