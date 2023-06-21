#include "lists.h"

/**
 * pall_t - Displays / prints all the elements of a stack_t stack
 * @top: Pointer to the top node of the stack
 * @arg: Unused variable, needed to keep function prototypes consistent
 *
 * Return: Nothing
 */
void pall_t(stack_t **top, int arg)
{
	stack_t *p;
	(void) arg;

	if (!top)
		return;

	p = *top;

	while (p != NULL)
	{
		printf("%d\n", p->n);
		p = p->prev;
	}
}
