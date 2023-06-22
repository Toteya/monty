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

	if (*top == NULL || (*top)->prev == NULL)
		return (13);

	p = *top;
	*top = (*top)->prev;
	(*top)->next = p->next;
	p->prev = (*top)->prev;
	(*top)->prev = p;
	p->next = *top;

	return (0);
}
