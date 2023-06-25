#include "monty.h"

/**
 * add_t - adds the top two nodes of a stack
 * @top: Double pointer to the top node of the stack
 *
 * Return: Nothing
 */
int add_t(stack_t **top)
{
	stack_t *p;

	if (*top == NULL || (*top)->next == NULL)
		return (14);

	p = *top;
	*top = (*top)->next;
	(*top)->n += p->n;
	(*top)->prev = NULL;
	free(p);

	return (0);
}
