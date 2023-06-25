#include "monty.h"

/**
 * sub_t - Subtracts the top element of the stack from the second
 * element of the stact.
 * @top: Double pointer to the top node of the stack
 *
 * Return: 0 on success. Otherwise 16 on failure.
 */
int sub_t(stack_t **top)
{
	stack_t *p;

	if (*top == NULL || (*top)->next == NULL)
		return (16);

	p = *top;
	*top = (*top)->next;
	(*top)->n -= p->n;
	(*top)->prev = NULL;
	free(p);

	return (0);
}
