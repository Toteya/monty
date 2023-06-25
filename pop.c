#include "monty.h"

/**
 * pop_t - Removes the top element of the stack
 * @top: Pointer to the top element of the stack
 *
 * Return: Nothing.
 */
int pop_t(stack_t **top)
{
	stack_t *p;

	if (*top == NULL)
		return (12);

	p = *top;
	*top = (*top)->next;
	if (*top != NULL)
		(*top)->prev = NULL;
	free(p);

	return (0);
}
