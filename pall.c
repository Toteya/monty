#include "monty.h"

/**
 * pall_t - Displays / prints all the elements of a stack_t stack
 * @top: Pointer to the top node of the stack
 *
 * Return: Nothing
 */
int pall_t(stack_t **top)
{
	stack_t *p;

	if (top == NULL)
		return (0);

	p = *top;

	while (p != NULL)
	{
		printf("%d\n", p->n);
		p = p->next;
	}

	return (0);
}
