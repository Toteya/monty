#include "monty.h"

/**
 * free_t - Frees a stack_t stack
 * @top: Pointer to the top node of the stack
 *
 * Return: Nothing
 */
void free_t(stack_t *top)
{
	stack_t *p;

	while (top)
	{
		p = top;
		top = top->prev;
		p->prev = NULL;
		free(p);
	}
}
