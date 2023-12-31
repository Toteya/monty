#include "monty.h"

/**
 * pchar_t - Prints the character (ASCII value) at the top of the stack_t
 * @top: Double pointer to the top of the stack
 *
 * Return: 0 on success. Otherwise return 21 or 210, depending on the error.
 */
int pchar_t(stack_t **top)
{
	if (*top != NULL)
	{
		if ((*top)->n >= 0 && (*top)->n < 128)
		{
			putchar((*top)->n);
			putchar('\n');
			return (0);
		}
		return (210);
	}
	return (21);
}
