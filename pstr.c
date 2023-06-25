#include "monty.h"

/**
 * pstr_t - Prints a string starting at the top of the stack.
 * @top: Double pointer to the top of the stack
 *
 * Return: 0 Always.
 */
int pstr_t(stack_t **top)
{
	stack_t *p;

	p = *top;
	while (p && p->n > 0 && p->n < 128)
	{
		putchar(p->n);
		p = p->next;
	}
	putchar('\n');
	return (0);
}
