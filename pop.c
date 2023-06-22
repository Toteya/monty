#include "monty.h"

/**
 * pop_t - Removes the top element of the stack
 * @top: Pointer to the top element of the stack
 * @line_nr: The current line number of the bytecode
 *
 * Return: Nothing.
 */
void pop_t(stack_t **top, unsigned int line_nr)
{
	stack_t *p;

	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_nr);
		exit(EXIT_FAILURE);
	}

	p = *top;
	*top = (*top)->prev;
	if (*top != NULL)
		(*top)->next = NULL;
	free(p);
}
