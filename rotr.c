#include "monty.h"

/**
 * rotr_t - Rotates the elements of the stack_t. Bottom becomes top,
 * and top becomes second
 * @top: Double pointer to the top of the stack.
 *
 * Return: Always 0.
 */
int rotr_t(stack_t **top)
{
	stack_t *p;

	if (*top == NULL || (*top)->next == NULL)
		return (0);

	p = *top;
	/* Find bottom element */
	while (p->next != NULL)
	{
		p = p->next;
	}

	/* Re-arrange element positions, bring bottom element to the top */
	(*top)->prev = p;
	p->next = *top;
	(p->prev)->next = NULL;
	p->prev = NULL;
	*top = p;

	return (0);
}
