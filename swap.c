#include "monty.h"

/**
 * swap_t - Swaps the top two elements of a stack_t
 * @top: Double pointer the top node of the stack
 *
 * Return: Nothing
 */
int swap_t(stack_t **top)
{
	stack_t *p;

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
