#include "monty.h"

/**
 * mod_t - Computes the remainder of the division of the second node by
 * the top node. Implements opcode "div"
 * @top: Double pointer to the top node of the stack
 * @line_nr: The current line number of the bytecode file
 *
 * Return: 0 on success. Otherwise return 19.
 */
int mod_t(stack_t **top, unsigned int line_nr)
{
	stack_t *p;
	(void) line_nr;

	if (*top == NULL || (*top)->next == NULL)
		return (19);
	if ((*top)->n == 0)
		return (190);

	p = *top;
	*top = (*top)->next;
	(*top)->n %= p->n;
	(*top)->prev = NULL;
	free(p);

	return (0);
}
