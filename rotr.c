#include "monty.h"

/**
 * rotr_t - Rotates the elements of the stack_t. Bottom becomes top,
 * and top becomes second
 * @top: Double pointer to the top of the stack.
 * @line_nr: The current line of the monty bytecode
 *
 * Return: Always 0.
 */
int rotr_t(stack_t **top, unsigned int line_nr)
{
	stack_t *p;
	(void) line_nr;

	if (*top == NULL || (*top)->prev == NULL)
		return (0);

	p = *top;
	/* Find bottom element */
	while (p->prev != NULL)
	{
		p = p->prev;
	}

	/* Re-arrange element positions, bring bottom element to the top */
	(*top)->next = p;
	p->prev = *top;
	(p->next)->prev = NULL;
	p->next = NULL;
	*top = p;

	return (0);
}
