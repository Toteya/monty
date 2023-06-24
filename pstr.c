#include "monty.h"

/**
 * pstr_t - Prints a string starting at the top of the stack.
 * @top: Double pointer to the top of the stack
 * @line_nr: The current line number of the monty bytecode
 *
 * Return: 0 Always.
 */
int pstr_t(stack_t **top, unsigned int line_nr)
{
	stack_t *p;
	(void) line_nr;

	if (*top == NULL)
		return (0);

	p = *top;
	while (p && p->n > 0 && p->n < 128)
	{
		putchar(p->n);
		p = p->prev;

	}
	putchar('\n');
	return (0);
}
