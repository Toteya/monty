#include "monty.h"

/**
 * pop_t - Removes the top element of the stack
 * @top: Pointer to the top element of the stack
 * @line_nr: The current line number of the bytecode
 *
 * Return: Nothing.
 */
int pop_t(stack_t **top, unsigned int line_nr)
{
	stack_t *p;
	(void) line_nr;

	if (*top == NULL)
		return (12);

	p = *top;
	*top = (*top)->prev;
	if (*top != NULL)
		(*top)->next = NULL;
	free(p);

	return (0);
}
