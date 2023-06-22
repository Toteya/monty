#include "monty.h"

/**
 * nop_t - Does not do anything. implements: NOP opcode
 * @top: Double pointer to the top node of a stack
 * @line_nr: The current line number in the bytecode
 *
 * Return: Nothing
 */
void nop_t(stack_t **top, unsigned int line_nr)
{
	(void) top;
	(void) line_nr;

}
