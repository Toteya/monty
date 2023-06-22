#include "monty.h"

/**
 * add_t - adds the top two nodes of a stack
 * @top: Double pointer to the top node of the stack
 * @line_nr: The current line number of the bytecode
 *
 * Return: Nothing
 */
int add_t(stack_t **top, unsigned int line_nr)
{
	stack_t *p;
	(void) line_nr;

	if (*top == NULL || (*top)->prev == NULL)
		return (14);

	p = *top;
	*top = (*top)->prev;
	(*top)->n += p->n;
	(*top)->next = NULL;
	free(p);

	return (0);
}
