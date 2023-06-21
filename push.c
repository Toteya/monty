#include "lists.h"

/**
 * push_t - Pushes a new element onto a stack_t stack (doubly linked list)
 * @top: Double pointer to the top node of the stack
 * @n: Integer data of the new elemeent
 *
 * Return: Address of the new element
 */
void push_t(stack_t **top, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;

	/* If the stack is not empty */
	if (*top != NULL)
	{
		new->prev = *top;
		(*top)->next = new;
	}
	*top = new;
}
