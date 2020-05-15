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
	{
		free((FILE *)to_free[0]);
		free((char *)to_free[1]);
		dprintf(STDERR_FILENO, NO_PCHAR, line_number), free_stack(*stack), EXIT_F;
	}
	ascii_value = (*stack)->n;

	if (ascii_value >= 0 && ascii_value  <= 127)
		printf("%c\n", ascii_value);
	else
	{
		free((FILE *)to_free[0]);
		free((char *)to_free[1]);
		dprintf(STDERR_FILENO, NO_VAL, line_number), EXIT_F;
	}
}

/**
 * p_str - prints a string based on ascii numbers
 *
 * @stack: double pointer to the top of stack
 * @line_number: unused
 *
 * Return: void
 *
 */
void p_str(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void)line_number;
	if (!stack || (!*stack))
		putchar('\n');

	node = *stack;

	while (node)
	{
		if (node->n >= 0 && node->n <= 127)
			putchar(node->n);
		else if (node->n < 0 || node->n > 127)
			break;
		node = node->next;
	}
	putchar('\n');
}
