#include "monty.h"

#define NO_PCHAR ("L%d: can't pchar, stack empty\n")
#define NO_VAL ("L%d: can't pchar, value out of range\n")
/**
 * p_char - prints the char at the top of the stack
 *
 * @stack: double pointer to head of stack
 * @line_number: line number to output for errors
 *
 * Return: void
 */
void p_char(stack_t **stack, unsigned int line_number)
{
	int ascii_value;

	if (!stack || (!*stack))
		dprintf(STDERR_FILENO, NO_PCHAR, line_number), exit(EXIT_FAILURE);

	ascii_value = (*stack)->n;


	if (ascii_value < 0 || ascii_value > 127)
		dprintf(STDERR_FILENO, NO_VAL, line_number), exit(EXIT_FAILURE);

	printf("%c\n", ascii_value);
}
