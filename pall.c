#include "monty.h"

/**
 * pall_t - Displays / prints all the elements of a stack_t stack
 * @top: Pointer to the top node of the stack
 * @line_nr: Current line number of the montu bytecode
 *
 * Return: Nothing
 */
int pall_t(stack_t **top, unsigned int line_nr)
{
	stack_t *p;
	(void) line_nr;

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
