#include "monty.h"

/**
 * push_t - Pushes a new element onto a stack_t stack (doubly linked list)
 * @top: Double pointer to the top node of the stack
 * @n: Integer data of the new element
 * @mode: Mode of operation: STACK_MODE=1, QUEUE_MODE=0
 *
 * Return: Address of the new element
 */
void push_t(stack_t **top, int n, int mode)
{
	stack_t *p, *new = NULL;
	(void) mode;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (*top == NULL)
	{
		*top = new;
		return;
	}

	if (mode == STACK_MODE)
	{
		new->next = *top;
		(*top)->prev = new;
		*top = new;
	}
	else
	{
		p = *top;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = new;
		new->prev = p;
	}
}
