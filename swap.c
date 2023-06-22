#include "monty.h"

/**
 * swap_t - Swaps the top two elements of a stack_t
 * @top: Double pointer the top node of the stack
 * @line_nr: The current line number of the bytecode
 *
 * Return: Nothing
 */
void swap_t(stack_t **top, unsigned int line_nr)
{
	stack_t *p;

	if (*top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_nr);
		exit(EXIT_FAILURE);
	}
	p = *top;
	*top = (*top)->prev;
	(*top)->next = p->next;
	p->prev = (*top)->prev;
	(*top)->prev = p;
	p->next = *top;
}
